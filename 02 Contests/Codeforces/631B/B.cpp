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

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	map<int, int> freq;
	bool poss = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
		if (freq[arr[i]] == 3) {
			poss = false;
		}
	}
	if (!poss) {
		cout << 0 << endl;
		return;
	}

	vector<pair<int, int>> ps;
	vector<int> res(n, 0);
	set<int> left; int left_max = 0;
	for (int i = 0; i < n - 1; i++) {
		if (left.find(arr[i]) != left.end()) {
			break;
		}
		left_max = max(left_max, arr[i]);
		left.insert(arr[i]);
		if (left_max == (int) left.size()) {
			res[i + 1]++;
		}
	}

	set<int> right; int right_max = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (right.find(arr[i]) != right.end()) {
			break;
		}
		right_max = max(right_max, arr[i]);
		right.insert(arr[i]);
		if (right_max == (int) right.size()) {
			res[i]++;
		}
	}


	for (int i = 0; i < n; i++) {
		if (res[i] == 2) {
			ps.push_back({ i, n - i });
		}
	}

	cout << ps.size() << endl;
	for (auto p : ps) {
		cout << p.first << " " << p.second << endl;
	}
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}
