// CSES Two Sets
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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n; cin >> n;
	set<int> st;
	for (int i = 1; i <= n; i++) st.insert(i);
	if ((n * (n + 1) / 2) & 1) {
		cout << "NO" << endl;
	} else if (n % 4 == 0) {
		vector<int> r1, r2;
		while (size(st)) {
			r1.pb(*st.begin());
			st.erase(st.begin());
			r1.pb(*st.rbegin());
			st.erase(*st.rbegin());
			r2.pb(*st.begin());
			st.erase(st.begin());
			r2.pb(*st.rbegin());
			st.erase(*st.rbegin());
		}
		cout << "YES" << endl;
		cout << size(r1) << endl;
		for (auto r : r1) cout << r << " ";
		cout << endl;
		cout << size(r2) << endl;
		for (auto r : r2) cout << r << " ";
		cout << endl;
	} else {
		if (n == 3) {
			cout << "YES\n2\n1 2\n1\n3\n";
		} else {
			cout << "YES" << endl;
			vector<int> r1 = { 1, 4 };
			vector<int> r2 = { 5 };
			st.erase(1);
			st.erase(4);
			st.erase(5);
			while (size(st)) {
				r1.pb(*st.begin());
				st.erase(st.begin());
				r1.pb(*st.rbegin());
				st.erase(*st.rbegin());
				r2.pb(*st.begin());
				st.erase(st.begin());
				r2.pb(*st.rbegin());
				st.erase(*st.rbegin());
			}
			cout << size(r1) << endl;
			for (auto r : r1) cout << r << " ";
			cout << endl;
			cout << size(r2) << endl;
			for (auto r : r2) cout << r << " ";
			cout << endl;
		}
	}
	return 0;
}