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
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    if (w * n < p) {
        cout << -1 << endl;
    } else {

        int x = p / w;
        int alpha = p % w;

        int lambda = -1;
        for (int i = 0; i < d; i++) {
            if ((alpha + i * w) % d == 0) {
                lambda = i;
                break;
            }
        }

        if (lambda == -1) {
            cout << -1 << endl;
        } else {
            x -= lambda;
            int y = (alpha + lambda * w) / d;

            if (x + y > n) {
                cout << -1 << endl;
            } else {
                if (x < 0) {
                    cout << -1 << endl;
                } else {
                    cout << x << " " << y << " " << n - x - y << endl;
                }
            }
        }
    }
    return 0;
}