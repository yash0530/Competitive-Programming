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
#define size(a) (int) a.size()

bool poss(string s) {
	int n = size(s);
	for (int i = 1; i < n; i++) {
		if(abs(s[i - 1] - s[i]) == 1) {
			return false;
		}
	}
	return true;
}

void solve() {
	string s; cin >> s;
	vector<int> freq(128);
	for (auto x : s) {
		freq[x]++;
	}
	vector<char> evens, odds;
	for (int i = 'a'; i <= 'z'; i++) {
		if (freq[i]) {
			if (i & 1) odds.push_back(i);
			else evens.push_back(i);
		}
	}
	string even = "", odd = "";
	for (auto e : evens) {
		for (int i = 0; i < freq[e]; i++) {
			even += e;
		}
	}
	for (auto e : odds) {
		for (int i = 0; i < freq[e]; i++) {
			odd += e;
		}
	}
	if (poss(even + odd)) {
		cout << even + odd << endl;
	} else if (poss(odd + even)) {
		cout << odd + even << endl;
	} else {
		cout << "No answer" << endl;
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		solve();
	}	    
    return 0;
}
