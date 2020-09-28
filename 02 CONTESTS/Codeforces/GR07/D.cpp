#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 23)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

#define h1 (int) (1e9 + 7)
#define h2 (int) (1e9 + 9)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string getPalin(string s, int k, int n) {
    string t;
    string sbar = s.substr(k, n - 2 * k);
    string sbar2 = sbar;
    reverse(sbar2.begin(), sbar2.end());
    sbar = sbar + '#' + sbar2;
    int k2 = prefix_function(sbar).back();
    t = s.substr(0, k) + sbar.substr(0, k2) + s.substr(n - k, k);
    return t;
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    int i = 0, j = n - 1, k = 0;
    while (i < j) {
        if (s[i] != s[j]) {
            break;
        }
        i++; j--; k++;
    }
    
    string t1 = getPalin(s, k, n);
    reverse(s.begin(), s.end());
    string t2 = getPalin(s, k, n);

    if (t1.length() > t2.length()) {
        cout << t1 << endl;
    } else {
        cout << t2 << endl;
    }
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}