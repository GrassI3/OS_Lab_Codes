<?php
$conn = mysqli_connect("127.0.0.1", "root", "", "Library");
if (!$conn) die("DB Error");

$msg = $_GET['msg'] ?? "";

/* ADD / UPDATE */
if (isset($_POST['save'])) {
    $id    = $_POST['BookId'];
    $title = $_POST['Title'];
    $pub   = $_POST['PublisherName'];
    $date  = $_POST['Publish_date'];
    // UPDATE
    if ($_POST['mode'] == 'edit') {
        mysqli_query($conn, "UPDATE Book SET Title='$title', PublisherName='$pub', Publish_date='$date' WHERE BookId=$id");
        header("Location: index.php?msg=Updated");
        exit;
    }
    // ADD
    else {
        if (!mysqli_query($conn,"INSERT INTO Book VALUES ($id,'$title','$pub','$date')")) {
            if (mysqli_errno($conn) == 1062)
                $msg = "Error: Book ID already exists";
            else
                $msg = "Insert error";
        } else {
            $msg = "Added";
        }
    }
}
/* DELETE */
if (isset($_GET['del'])) {
    mysqli_query($conn, "DELETE FROM Book WHERE BookId=".$_GET['del']);
    header("Location: index.php?msg=Deleted");
    exit;
}
/* EDIT */
$edit = null;
if (isset($_GET['edit'])) {
    $res = mysqli_query($conn, "SELECT * FROM Book WHERE BookId=".$_GET['edit']);
    $edit = mysqli_fetch_assoc($res);
}
/* FETCH */
$books = mysqli_query($conn, "SELECT * FROM Book ORDER BY BookId");
?>

<!DOCTYPE html>
<html>
<head>
<title>Simple Books CRUD</title>
</head>
<body>
<h3><?= $msg ?></h3>
<form method="post">
<input type="hidden" name="mode" value="<?= $edit ? 'edit' : 'add' ?>">
ID:
<input name="BookId" value="<?= $edit['BookId'] ?? '' ?>"<?= $edit ? 'readonly' : 'required' ?>><br><br>
Title:
<input name="Title" value="<?= $edit['Title'] ?? '' ?>" required><br><br>
Publisher:
<input name="PublisherName" value="<?= $edit['PublisherName'] ?? '' ?>"><br><br>
Date:
<input type="date" name="Publish_date" value="<?= $edit['Publish_date'] ?? '' ?>"><br><br>
<button name="save"><?= $edit ? 'Update' : 'Add' ?></button>
<?php if ($edit): ?><a href="index.php">Cancel</a><?php endif; ?>
</form>

<hr>

<?php while ($b = mysqli_fetch_assoc($books)): ?>
<?= $b['BookId'] ?> |
<?= $b['Title'] ?> |
<a href="?edit=<?= $b['BookId'] ?>">Edit</a> |
<a href="?del=<?= $b['BookId'] ?>" onclick="return confirm('Delete?')">Delete</a>
<br>
<?php endwhile; ?>
</body>
</html>