#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        vector<int> H(26);
        for (auto x : a) {
            H[x - 'a']++;
        }
        bool possible = false;
        for (auto y : b) {
            if (H[y - 'a'] > 0) {
                possible = true;
                break;
            }
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
}