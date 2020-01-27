#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int max_poss = n / 2;
        while (max_poss > 0) {
            if (arr[max_poss] < arr[max_poss - 1]) {
                break;
            }
            max_poss--;
        }
        bool possible = max_poss;
        int gold = 0, silver = 0, bronze = 0;
        for (int i = 0; i < max_poss; i++) {
            if (i == max_poss - 1) {
                possible = false;
                break;
            }
            if (arr[i] != arr[i + 1]) {
                gold = i + 1;
                break;
            }
        }
        if (possible) {
            for (int i = gold; i < max_poss; i++) {
                if (i == max_poss - 1) {
                    possible = false;
                    break;
                }
                if ((arr[i] != arr[i + 1]) and (i - gold + 1) > gold) {
                    silver = i - gold + 1;
                    break;
                }
            }
            if (possible) {
                bronze = max_poss - gold - silver;
                if (bronze > gold){
                    cout << gold << " " << silver << " " << bronze << endl;
                } else {
                    cout << "0 0 0" << endl;
                }
            } else {
                cout << "0 0 0" << endl;
            }
        } else {
            cout << "0 0 0" << endl;
        }
    }
    return 0;
}