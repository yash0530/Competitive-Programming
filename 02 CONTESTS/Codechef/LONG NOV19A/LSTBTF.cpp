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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

bool isPerfectSquare(int n, int rem_sum) {
    int sum = rem_sum;
    while (n > 0) {
        int x = n % 10;
        if (x == 0) return false;
        sum += x * x;
        n /= 10;
    }
    int sq = (int) sqrt(sum);
    return sq * sq == (sum);
}



getMat(dp, 20000, 200, -1);

bool isPossible(int x, int y) {
    if (x < 0) return false;
    if (x == 0 and y == 0) return true;
    if (y == 0) return false;
    if (dp[x][y] != -1) return dp[x][y];
    if (y == 1) {
        int sq = sqrt(x);
        dp[x][y] = (sq < 10 and sq > 0) and ((sq * sq) == x);
        return dp[x][y];
        // return (sq < 10 and sq > 0) and ((sq * sq) == x);
    }
    for (int i = 1; i <= 9; i++) {
        if (x - (i * i) >= 0) {
            if (isPossible(x - (i * i), y - 1)) {
                dp[x][y] = true;
                return dp[x][y];
                // return true;
            }
        } else {
            break;
        }
    }
    dp[x][y] = false;
    return dp[x][y];
    // return false;
}

void printNumbers(int digits, int sum) {
    if (digits == 0) return;
    for (int i = 1; i <= 9; i++) {
        if (isPossible(sum - i * i, digits - 1)) {
            cout << i;
            printNumbers(digits - 1, sum - i * i);
            return;
        }
    }
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n < 1000) {
            int my_sum = n;
            int x = 1;
            while (true) {
                int a = my_sum - floor(log10(x)) - 1;
                if (isPerfectSquare(x, a)) {
                    for (int i = 0; i < a; i++) {
                        cout << 1;
                    }
                    cout << x;
                    cout << endl;
                    break;
                }
                x++;
            }
        } else {
            int sq = ceil(sqrt(n));
            // bool found = false;
            vector<pair<int, int>> pts;
            for (int i = 0; i < 10; i++) {
                int potential = (sq + i) * (sq + i);
                int diff = potential - n;
                for (int j = 0; j <= min((int) 100, n); j++) {
                    if (isPossible(diff, j)) {
                        pts.push_back({ j, diff });
                    }
                    diff++;
                }
                
                // if (found) break;
            }

            pair<int, int> alpha = *min_element(pts.begin(), pts.end());
            for (int i = 0; i < n - alpha.first; i++) {
                cout << 1;
            }
            printNumbers(alpha.first, alpha.second);
            cout << endl;
            // deb(alpha.second);
            // deb(alpha.first);
        }
        // cout << endl;
    }
    return 0;
}