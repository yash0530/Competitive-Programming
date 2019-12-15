// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
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
#define sort(x) sort(x.begin(), x.end())
#define reverse(x) reverse(x.begin(), x.end())

int32_t main() {
    fastio;
    int n; cin >> n;
    string s; cin >> s;
    int count = 0, a = 0, b = 0;
    string res = "";
    for (int i = 0; i < n; i++) {
        if (a == b) {
            res.push_back(s[i]);
            b += s[i] == 'b';
            a += s[i] == 'a';
        } else if (a > b) {
            if (s[i] == 'a') {
                count++;
            }
            res.push_back('b');
            b++;
        } else {
            if (s[i] == 'b') {
                count++;
            }
            res.push_back('a');
            a++;
        }
    }
    cout << count << endl;
    cout << res << endl;
    return 0;
}