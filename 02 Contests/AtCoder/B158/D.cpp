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

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    string s; cin >> s;
    int q; cin >> q;
    deque<char> d; bool rev = false;
    for (auto x : s) {
        d.push_back(x);
    }
    while (q--) {
        int x; cin >> x;
        if (x == 1) rev = !rev;
        else {
            int a; char b;
            cin >> a >> b;
            if (a == 1) {
                if (rev) {
                    d.push_back(b);
                } else {
                    d.push_front(b);
                }
            } else {
                if (rev) {
                    d.push_front(b);
                } else {
                    d.push_back(b);
                }
            }
        }
    }
    if (rev) {
        while (!d.empty()) {
            cout << d.back();
            d.pop_back();
        }
        cout << endl;
    } else {
        while (!d.empty()) {
            cout << d.front();
            d.pop_front();
        }
        cout << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}