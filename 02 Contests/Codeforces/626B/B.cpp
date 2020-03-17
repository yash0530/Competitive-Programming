#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int n, m, k, x;
    cin >> n >> m >> k;

    vector<int> factors = getFactors(k);
    sort(factors.begin(), factors.end());

    vector<int> A, B;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (prev != 0)
                A.push_back(prev);
            prev = 0;
        }
        prev += x;
    }
    if (prev != 0)
        A.push_back(prev);
    sort(A.begin(), A.end());

    prev = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 0) {
            if (prev != 0) 
                B.push_back(prev);
            prev = 0;
        }
        prev += x;
    }
    if (prev != 0)
        B.push_back(prev);
    sort(B.begin(), B.end());

    vector<pair<int, int>> a, b;
    for (auto x : A) {
        if (a.empty()) {
            a.push_back({ x, 1 });
        } else if (a.back().first == x) {
            a[a.size() - 1].second++;
        } else {
            a.push_back({ x, 1 });
        }
    }

    for (auto x : B) {
        if (b.empty()) {
            b.push_back({ x, 1 });
        } else if (b.back().first == x) {
            b[b.size() - 1].second++;
        } else {
            b.push_back({ x, 1 });
        }
    }

    int res = 0;
    for (auto a1 : a) {
        for (auto b1 : b) {
            if (a1.first * b1.first >= k) {
                int i = 0, j = factors.size() - 1;
                int curr = 0;
                while (i <= j) {
                    int x = factors[i], y = factors[j];
                    if (i == j) {
                        if (a1.first >= x and b1.first >= y) {
                            curr += (a1.first - x + 1) * (b1.first - y + 1);
                        }
                    }
                    else {
                        if (a1.first >= x and b1.first >= y) {
                            curr += (a1.first - x + 1) * (b1.first - y + 1);
                        }
                        if (b1.first >= x and a1.first >= y) {
                            curr += (b1.first - x + 1) * (a1.first - y + 1);
                        }
                    }
                    i++; j--;
                }
                res += curr * a1.second * b1.second;
            }
        }
    }
    cout << res << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}