#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int h; cin >> h;
        cout << 1 << " " << 2 << endl;
        fflush(stdout);

        int level; cin >> level;
        cout << 2 << " " << 2 << " " << level << endl;
        fflush(stdout);
        int node; cin >> node;
        int count = node > 0;

        for (int i = 0; i < 2 * h - 1; i++) {
            cout << 2 << " " << node << " " << 2 * h - 1 << endl;
            fflush(stdout);
            int x; cin >> x;
            count += (x > 0);
            if (x > 0) {
                node = x;
            }
        }

        cout << 3 << " " << count << endl;
        fflush(stdout);
        int x; cin >> x;
    }
    return 0;
}