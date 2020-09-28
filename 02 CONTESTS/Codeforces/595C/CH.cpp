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
#define MOD (int) (1e9 + 7)

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

string getStr(int n) {
    string s;
    while (n != 0) {
        s.push_back('0' + (n % 3));
        n /= 3;
    }
    return s;
}

int getNum(string s) {
    int n = 0, b = 1;
    for (auto x : s) {
        n += (x - '0') * b;
        b *= 3;
    }
    return n;
}

int32_t main() {
    fastio;
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string s = getStr(n);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '2') {
                s[i] = '0';
                int j = i + 1;
                while (j < s.length() and s[j] == '2') {
                    s[j] = '0';
                    j++;
                }
                if (j == s.length()) {
                    for (int i = 0; i < s.length(); i++) {
                        s[i] = '0';
                    }
                    s.push_back('1');
                    break;
                } else {
                    for (int i = 0; i < j; i++) {
                        s[i] = '0';
                    }
                    s[j]++;
                }
            }
        }
        cout << getNum(s) << endl;
    }
    return 0;
}