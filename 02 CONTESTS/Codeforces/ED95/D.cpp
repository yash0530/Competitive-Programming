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
	int n, q;
	cin >> n >> q;
	set<int> vals;
	multiset<int> gaps;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		vals.insert(arr[i]);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		gaps.insert(arr[i] - arr[i - 1]);
	}
	if (size(vals) and size(gaps)) {
		cout << *vals.rbegin() - *vals.begin() - *gaps.rbegin() << endl;
	} else {
		cout << 0 << endl;
	}
	while (q--) {
		int type, val; cin >> type >> val;
		if (type == 1) {
			auto it = vals.upper_bound(val);
			if (vals.empty()) {
				vals.insert(val);
			} else if (it != vals.begin() and it != vals.end()) {
				auto prev = --it;
				++it;
				int d = *it - *prev;
				gaps.erase(gaps.find(d));
				gaps.insert(*it - val);
				gaps.insert(val - *prev);
				vals.insert(val);
			} else if (it != vals.begin()) {
				--it;
				gaps.insert(abs(val - *it));
				vals.insert(val);
			} else if (it != vals.end()) {
				gaps.insert(abs(val - *it));
				vals.insert(val);
			}
		} else {
			auto it = vals.find(val);
			if (size(vals) == 1) {
				vals.erase(val);
			} else if ((it != vals.begin()) and (val != *vals.rbegin())) {
				auto prev = --it;
				++it;
				auto back = ++it;
				--it;
				gaps.insert(*back - *prev);
				gaps.erase(gaps.find(*it - *prev));
				gaps.erase(gaps.find(*back - *it));
				vals.erase(val);
			} else if (val == *vals.begin()) {
				gaps.erase(gaps.find(*(++it) - val));
				vals.erase(val);
			} else if (val == *vals.rbegin()) {
				gaps.erase(gaps.find(val - *(--it)));
				vals.erase(val);
			}
		}
		if (size(vals) and size(gaps)) {
			cout << *vals.rbegin() - *vals.begin() - *gaps.rbegin() << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}