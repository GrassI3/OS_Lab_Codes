#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    int block[m];
    for (int i = 0; i < m; i++) cin >> block[i];
    int p, pid = 1;
    while (cin >> p && p != -1) {
        bool allocated = false;
        for (int i = 0; i < m; i++) {
            if (block[i] >= p) {
                block[i] -= p;
                allocated = true;
                break;
            }
        }
        if (allocated) cout << "Process " << pid << " ( size " << p << " KB ) was allocated\n";
        else cout << "Process " << pid << " ( size " << p << " KB ) was not allocated -> External Fragmentation\n";
        pid++;
    }
}