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
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	vector<int> ans_v;
	for (int i = 0; i <= n; i++) {
		int res = 0, prev = arr[i];
		vector<int> temp; 
		for (int j = i; j > 0; j--) {
			int curr = min(arr[j], prev);
			res += curr;
			prev = curr;
			temp.pb(curr);
		}
		reverse(temp.begin(), temp.end());
		prev = arr[i];
		for (int j = i + 1; j <= n; j++) {
			int curr = min(arr[j], prev);
			res += curr;
			prev = curr;
			temp.pb(curr);
		}
		if (ans < res) {
			ans = res;
			ans_v = temp;
		}
	}
	for (auto a : ans_v) {
		cout << a << " ";
	} cout << endl;
	return 0;
}
