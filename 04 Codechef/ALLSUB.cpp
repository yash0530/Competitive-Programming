#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        string s, r; cin >> s >> r;
        vector<int> Fs(26), Fr(26);
        for (auto x : s) {
            Fs[(x - 'a')]++;
        }
        for (auto x : r) {
            Fr[(x - 'a')]++;
        }
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (Fr[i] < Fs[i]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "Impossible" << endl;
        } else {

            for (int i = 0; i < 26; i++) {
                Fr[i] = Fr[i] - Fs[i];
            }

            char x = s[0]; int j = 1;
            while (x == s[j] and j < (int) s.length()) {
                j++;
            }
            int stat = 0;
            if (j != (int) s.length()) {
                stat = x - s[j];
            }
            if (stat > 0) {
                for (int i = 0; i < (x - 'a'); i++) {
                    while (Fr[i] != 0) {
                        Fr[i]--;
                        cout << char(i + 'a');
                    }
                }
                for (auto l : s) {
                    cout << l;
                }
                for (int i = (x - 'a'); i < 26; i++) {
                    while (Fr[i] != 0) {
                        Fr[i]--;
                        cout << char(i + 'a');
                    }
                }
            } else {
                for (int i = 0; i <= (x - 'a'); i++) {
                    while (Fr[i] != 0) {
                        Fr[i]--;
                        cout << char(i + 'a');
                    }
                }
                for (auto l : s) {
                    cout << l;
                }
                for (int i = (x - 'a') + 1; i < 26; i++) {
                    while (Fr[i] != 0) {
                        Fr[i]--;
                        cout << char(i + 'a');
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}