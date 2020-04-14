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

int32_t main() { fastio;
	int n; cin >> n;
	int a[n], b[n];
	set<int> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) x.insert(a[i]); 
	}
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		dq.push_back(b[i]);
	}
	int count = 0, poss = true;
	while (!x.empty()) {
		int y = *x.begin();
		if (dq.back() != y - 1) {
			poss = false;
			break;
		}
		dq.push_back(y);
		int z = dq.front(); dq.pop_front();
		if (z) {
			x.insert(z);
		}
		x.erase(y);
		count++;
	}
	int i = 1;
	for (auto d : dq) {
		if (d != i) {
			poss = false;
			break;
		}
		i++;
	}
	if (poss) {
		cout << count << endl;
	} else {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (b[i]) {
				res = max(res, (i + 1) - b[i] + 1 + n);
			}
		}
		cout << res << endl;
	}
    return 0;
}
