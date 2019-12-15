#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        
        ll odds = 0;
        ll rows[n];
        ll cols[n];
        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);
        ll e1 = n, o1 = 0, e2 = n, o2 = 0, r, c;
        while (q--) {
            cin >> r >> c;
            r--; c--;
            rows[r]++;
            cols[c]++;
            if (rows[r] & 1) {
                o1++; e1--;
            } else {
                o1--; e1++;
            }
            if (cols[c] & 1) {
                o2++; e2--;
            } else {
                o2--; e2++;
            }
        }
        cout << e1 * o2 + e2 * o1 << endl;
    }

    return 0;
}