#include <iostream>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n;
    cin >> n;

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].bt >> p[i].at;
        p[i].rt = p[i].bt;
    }

    int time = 0, completed = 0;
    cout << "Gantt: ";

    while (completed < n) {
        int idx = -1, minRT = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].rt < minRT) {
                    minRT = p[i].rt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        cout << "P" << p[idx].id << " ";

        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            completed++;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
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