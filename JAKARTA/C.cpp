#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() { fastio;
    int n, q;
    cin >> n >> q;
    vector<int> R(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    vector<int> PR(n), PC(n);
    PR[0] = 0;
    PC[0] = 0;
    for (int i = 1; i < n; i++) {
        PR[i] = ((R[i] & 1) == (R[i - 1] & 1)) ? PR[i - 1] : 1 + PR[i - 1];
        PC[i] = ((C[i] & 1) == (C[i - 1] & 1)) ? PC[i - 1] : 1 + PC[i - 1];
    }
    int a, b, c, d;
    while (q--) {
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if (PR[a] == PR[c] and PC[b] == PC[d]) {
            if ((R[a] & 1) == (C[b] & 1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}