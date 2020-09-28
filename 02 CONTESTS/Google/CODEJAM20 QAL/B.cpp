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
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

vector<pair<string, string>> x = {
	{ "", "" },
	{ "(", ")" },
	{ "((", "))" },
	{ "(((", ")))" },
	{ "((((", "))))" },
	{ "(((((", ")))))" },
	{ "((((((", "))))))" },
	{ "(((((((", ")))))))" },
	{ "((((((((", "))))))))" },
	{ "(((((((((", ")))))))))" },
};

int32_t main() { fastio;
    int t; cin >> t;
    for (int _ = 1; _ <= t; _++) {
    	cout << "Case #" << _ << ": ";
    	string s; cin >> s;
    	string r;
    	for (int i = 0; i < (int) s.length(); i++) {
    		r += x[s[i] - '0'].first + s[i] + x[s[i] - '0'].second;
    	}
    	int alpha = r.length();
    	vector<int> res(alpha, 0);
    	for (int i = 0; i < alpha - 1; i++) {
    		if (r[i] == ')' and r[i + 1] == '(') {
    			int low = i, high = i + 1;
    			while (low >= 0 and high < alpha) {
    				if (r[low] == ')' and r[high] == '(') {
    					res[low] = 1; res[high] = 1;
    					low--; high++;
    				} else {
    					break;
    				}
    			}
    			i = high;
    		}
    	}
    	for (int i = 0; i < alpha; i++) {
    		if (res[i] == 0) {
    			cout << r[i];
    		}
    	} cout << endl;
    }
    return 0;
}
