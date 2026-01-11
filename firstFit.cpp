#include <bits/stdc++.h>
using namespace std;
struct Segment {
    string name;
    int size;
    bool free;
};
void printMemState(const vector<Segment>& mem) {
    for (const auto& seg : mem) {
        cout << "+------------------------------------------+\n";
        if (seg.free) cout << "[ Free ( Size: " << seg.size << " KB ) ]\n";
        else cout << "[ " << seg.name << " ( Allocated: " << seg.size << " KB ) ]\n";
    } cout << "+------------------------------------------+\n";
    cout << endl;
}
void firstFit(vector<Segment>& mem, int p[], int n) {
    for (int i = 0; i < n; i++) {
        bool allocated = false;
        for (int j = 0; j < mem.size(); j++) {
            if (mem[j].free && mem[j].size >= p[i]) {
                Segment allocatedSeg;
                allocatedSeg.name = "Process " + to_string(i + 1);
                allocatedSeg.size = p[i];
                allocatedSeg.free = false;
                mem[j].size -= p[i];
                mem.insert(mem.begin() + j, allocatedSeg);
                if (mem[j + 1].size == 0) mem.erase(mem.begin() + j + 1);
                allocated = true;
                break;
            }
        }
        if (allocated) cout << "Process " << i + 1 << " ( size " << p[i] << " KB ) was allocated\n";
        else cout << "Process " << i + 1 << " ( size " << p[i] << " KB ) was not allocated -> External Fragmentation\n";
        printMemState(mem);
    }
}
int main() {
    int m, n;
    cout << "Enter number of blocks: "; cin >> m;
    vector<Segment> mem;
    cout << "Enter size of blocks:\n";
    for (int i = 0; i < m; i++) {
        int size; cin >> size;
        mem.push_back({"Free", size, true});
    }
    cout << "Enter number of processes: "; cin >> n;
    int p[n];
    cout << "Enter size of processes:\n";
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << "\nInitial Memory State:\n";
    printMemState(mem);
    firstFit(mem, p, n);
}