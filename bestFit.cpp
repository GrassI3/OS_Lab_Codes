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
            int best = -1;
            for (int j = 0; j < m; j++) {
                if(block[j]>=p && (best == -1 || block[j]<block[best])) {
                    best = j;
                }
            }
            if (best != -1 && block[best] >= p) {
                block[best] -= p;
                allocated = true;
                break;
            }
        }
        if (allocated) cout << "Process " << pid << " ( size " << p << " KB ) was allocated\n";
        else cout << "Process " << pid << " ( size " << p << " KB ) was not allocated -> External Fragmentation\n";
        pid++;
    }
}