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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> freq(2e5 + 5);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
	}
	priority_queue<pii> pq;
	priority_queue<pair<pii, pii>> avails;
	for (int i = 1; i <= 2e5; i++) {
		if (freq[i]) {
			pq.push({ freq[i], i });
		}
	}
	vector<int> res;
	while (size(res) < k) {
		pii top = pq.top();
		if (pq.empty() or !avails.empty()) {
			auto tempTop = avails.top();
			if (pq.empty() or tempTop.fs.fs >= top.fs) {
				avails.pop();
				if (freq[tempTop.fs.sc] > (tempTop.sc.fs + 1)) {
					avails.push({ { tempTop.sc.sc / (tempTop.sc.fs + 2), tempTop.fs.sc }, { tempTop.sc.fs + 1, tempTop.sc.sc } });
				}
				res.pb(tempTop.fs.sc);
			} else {
				pq.pop();
				if (freq[top.sc] > 1)
					avails.push({ { top.fs / 2, top.sc }, { 1, top.fs } });
				res.pb(top.sc);
			}
		} else {
			pq.pop();
			if (freq[top.sc] > 1)
				avails.push({ { top.fs / 2, top.sc }, { 1, top.fs } });
			res.pb(top.sc);
		}
	}
	for (auto r : res) {
		cout << r << " ";
	} cout << endl;
	return 0;
}
