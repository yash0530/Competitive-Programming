#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)

int n, k;
vector<bitset<7>> arr;
vector<string> strs = {
	"1110111", "0010010", "1011101", "1011011", "0111010", 
	"1101011", "1101111", "1010010", "1111111", "1111011" 
};
vector<bitset<7>> valids;
const int maxN = 2005;
int dp[maxN][maxN];

bool check(bitset<7> x) {
	for (auto v : valids) {
		if (v == x) return true;
	}
	return false;
}

int canDo(bitset<7> a, bitset<7> b) {
	bitset<7> temp = a | b;
	if (temp.count() > b.count()) {
		return -1;
	}
	return b.count() - a.count();
}

bool res(int ind = 0, int rem = k) {
	if (ind == n) {
		dp[ind][rem] = (rem == 0);
		return rem == 0;
	}
	if (rem == 0) {
		if (check(arr[ind])) {
			dp[ind][rem] = res(ind + 1, rem);
		} else {
			dp[ind][rem] = false;
		}
	}
	int &ans = dp[ind][rem];
	if (ans == -1) {
		ans = 0;
		for (int i = 9; i >= 0; i--) {
			int reqd = canDo(arr[ind], valids[i]);
			if (reqd >= 0 and reqd <= rem) {
				ans = ans or res(ind + 1, rem - reqd);
			}
		}
	}
	return ans;
}

int getVal(bitset<7> a) {
	for (int i = 0; i <= 9; i++) {
		if (valids[i] == a) {
			return i;
		}
	}
	return -1;
}

vector<int> final;
void genAns(int ind = 0, int rem = k) {
	if (ind == n) {
		return;
	}
	if (rem == 0) {
		final.pb(getVal(arr[ind]));
		genAns(ind + 1, 0);
	} else {
		for (int i = 9; i >= 0; i--) {
			int reqd = canDo(arr[ind], valids[i]);
			if (reqd >= 0 and reqd <= rem) {
				if (dp[ind + 1][rem - reqd] == 1) {
					final.pb(i);
					return genAns(ind + 1, rem - reqd);
				}
			}
		}
	}
}

int32_t main() { fastio;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i <= 9; i++) {
		bitset<7> a(strs[i]);
		valids.pb(a);
	}

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		bitset<7> b(s);
		arr.pb(b);
	}
	if (!res()) {
		cout << -1 << endl;
	} else {
		genAns();
		for (auto f : final) {
			cout << f;
		} cout << endl;
	}

	return 0;
}
