#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq;
    cin >> n >> tq;

    Process p[n];
    queue<int> q;

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].bt >> p[i].at;
        p[i].rt = p[i].bt;
    }

    int time = 0, completed = 0;
    cout << "Gantt: ";

    while (completed < n) {
        for (int i = 0; i < n; i++)
            if (p[i].at == time)
                q.push(i);

        if (q.empty()) {
            time++;
            continue;
        }

        int i = q.front();
        q.pop();

        int exec = min(tq, p[i].rt);
        cout << "P" << p[i].id << " ";

        time += exec;
        p[i].rt -= exec;

        for (int j = 0; j < n; j++)
            if (p[j].at > time - exec && p[j].at <= time)
                q.push(j);

        if (p[i].rt > 0)
            q.push(i);
        else {
            completed++;
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
    }

    double avgWT = 0, avgTAT = 0;

    cout << "\nPID AT BT CT TAT WT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << " "
             << p[i].at << " "
             << p[i].bt << " "
             << p[i].ct << " "
             << p[i].tat << " "
             << p[i].wt << "\n";

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    cout << "Avg WT: " << avgWT / n << "\n";
    cout << "Avg TAT: " << avgTAT / n << "\n";

    return 0;
}