#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) { for (auto b : a) cout << b << " "; cout << "\n"; } cout << "\n";
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cina(x, n) vector<int> x(n); for (int i = 0; i < n; i++) cin >> x[i];
#define srt(x) sort(x.begin(), x.end())
#define rev(x) reverse(x.begin(), x.end())
 
int32_t main() {
    fastio;
 
    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> arr(n);
        for (auto &a : arr) cin >> a;
        for (auto &a : arr) {
            if (a > q) {
                a = 0;
            } else {
                a = 1;
            }
        }
 
        vector<int> pb;
        pb.push_back(0);
        int sum = 0;
        for (auto a : arr) {
            if (a == 0 && pb.back() != 0) {
                if (pb.back() >= k) {
                    sum += (pb.back() - k + 1) * (pb.back() - k + 2) / 2;
                }
                pb.push_back(0);
            } else if (a == 0) {
            } else {
                pb[size(pb) - 1]++;
            }
        }
        if (pb.back() != 0) {
            if (pb.back() >= k) {
                sum += (pb.back() - k + 1) * (pb.back() - k + 2) / 2;
            }
        } 
        cout << sum << endl;
    }
    
    return 0;
}
