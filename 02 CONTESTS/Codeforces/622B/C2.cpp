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

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> arr(n + 2);
	vector<pii> vals;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	stack<int> st; st.push(0);
	vector<int> nearest_g(n + 2);
	for (int i = 1; i <= n; i++) {
		while (arr[st.top()] > arr[i]) st.pop();
		nearest_g[i] = st.top();
		st.push(i);
	}
	vector<int> pref(n + 2), suff(n + 2);
	int prev = arr[0];
	for (int i = 1; i <= n; i++) {
		int pos = nearest_g[i];
		pref[i] = pref[pos] + (i - pos) * arr[i];
		prev = arr[i];
	}

	reverse(arr.begin(), arr.end());
	st = stack<int>(); st.push(0);
	vector<int> nearest_s(n + 2);
	for (int i = 1; i <= n; i++) {
		while (arr[st.top()] > arr[i]) st.pop();
		nearest_s[i] = st.top();
		st.push(i);
	}
	prev = arr[0];
	for (int i = 1; i <= n; i++) {
		int pos = nearest_s[i];
		suff[i] = suff[pos] + (i - pos) * arr[i];
		prev = arr[i];
	}
	reverse(arr.begin(), arr.end());
	reverse(suff.begin(), suff.end());

	int best = 0, val = pref[0] + suff[1];
	for (int i = 1; i <= n; i++) {
		if (val <= (pref[i] + suff[i + 1])) {
			val = pref[i] + suff[i + 1];
			best = i;
		}
	}

	prev = arr[best];
	vector<int> ans_v; 
	for (int j = best; j > 0; j--) {
		int curr = min(arr[j], prev);
		prev = curr;
		ans_v.pb(curr);
	}
	reverse(ans_v.begin(), ans_v.end());
	if (best == 0) prev = arr[best + 1];
	else prev = arr[best];
	for (int j = best + 1; j <= n; j++) {
		int curr = min(arr[j], prev);
		prev = curr;
		ans_v.pb(curr);
	}
	for (auto a : ans_v) {
		cout << a << " ";
	} cout << endl;
	return 0;
}
