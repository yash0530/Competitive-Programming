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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int n, x; cin >> n;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = { x, i + 1 };
	}
	sort(arr.begin(), arr.end());

	vector<int> diffs;
	map<int, int> ds;
	vector<pii> rems;
	for (int i = 1; i < n; i++) {
		diffs.pb(arr[i].fs - arr[i - 1].fs);
		ds[arr[i].fs - arr[i - 1].fs]++;
		if (i != n - 1) {
			rems.pb({ diffs.back(), arr[i + 1].fs - arr[i].fs });
		}
	}

	if (n <= 3) {
		cout << 1 << endl;
	} else if (size(ds) > 3) {
		cout << -1 << endl;
	} else if (size(ds) == 1) {
		cout << arr[0].sc << endl;
	} else if (size(ds) == 2) {
		if (ds[arr[1].fs - arr[0].fs] == 1) {
			cout << arr[0].sc << endl;
		} else if (ds[arr[n - 1].fs - arr[n - 2].fs] == 1) {
			cout << arr.back().sc << endl;
		} else {
			int loc = -1;
			for (int i = 0; i < size(rems); i++) {
				ds[rems[i].fs]--;
				ds[rems[i].sc]--;
				ds[rems[i].fs + rems[i].sc]++;
				int ct = 0;
				for (auto d : ds) ct += (d.sc > 0);
				if (ct == 1) loc = arr[i + 1].sc;
				ds[rems[i].fs]++;
				ds[rems[i].sc]++;
				ds[rems[i].fs + rems[i].sc]--;
			}
			cout << loc << endl;
		}	
	} else {
		int loc = -1;
		for (int i = 0; i < size(rems); i++) {
			ds[rems[i].fs]--;
			ds[rems[i].sc]--;
			ds[rems[i].fs + rems[i].sc]++;
			int ct = 0;
			for (auto d : ds) ct += (d.sc > 0);
			if (ct == 1) loc = arr[i + 1].sc;
			ds[rems[i].fs]++;
			ds[rems[i].sc]++;
			ds[rems[i].fs + rems[i].sc]--;
		}
		cout << loc << endl;
	}
	return 0;
}
