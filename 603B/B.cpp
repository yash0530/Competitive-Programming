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
        map<string, int> freq;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        int count = 0;
        for (auto f : freq) {
            count += f.second - 1;
        }
        cout << count << endl;
        for (auto a : arr) {
            if (freq[a] > 1) {
                for (int i = 0; i < 10; i++) {
                    string s = a.substr(0, 3) + to_string(i);
                    if (freq.find(s) == freq.end()) {
                        freq[s]++;
                        freq[a]--;
                        cout << s << endl;
                        break;
                    }
                }
            } else {
                cout << a << endl;
            }
        }
    }
    return 0;
}