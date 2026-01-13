#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& alloc,
            vector<vector<int>>& need,
            vector<int>& avail) {

    int n = alloc.size(), m = avail.size();
    vector<int> work = avail;
    vector<bool> finish(n, false);
    vector<int> safe;

    for (int c = 0; c < n; ) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j]) break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = true;
                    safe.push_back(i);
                    found = true;
                    c++;
                }
            }
        }

        if (!found) {
            cout << "Unsafe state\n";
            return false;
        }
    }

    cout << "Safe sequence: ";
    for (int i : safe) cout << "P" << i << " ";
    cout << "\n";
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    for (int j = 0; j < m; j++)
        cin >> avail[j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    isSafe(alloc, need, avail);

    // Immediate request
    int p;
    cin >> p;

    vector<int> req(m);
    for (int j = 0; j < m; j++) cin >> req[j];

    for (int j = 0; j < m; j++) {
        if (req[j] > need[p][j] || req[j] > avail[j]) {
            cout << "Request denied\n";
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
        need[p][j] -= req[j];
    }

    if (!isSafe(alloc, need, avail))
        cout << "Request denied\n";
    else
        cout << "Request granted\n";

    return 0;
}