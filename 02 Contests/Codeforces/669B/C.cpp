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
	if (n == 1) {
		cout << "! 1" << endl;
		exit(0);
	}
	set<int> S;
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		S.insert(i);
	}
	while (size(S) >= 2) {
		int a = *S.begin();
		S.erase(S.begin());
		int b = *S.begin();
		S.erase(S.begin());
		cout << "? " << a + 1 << " " << b + 1 << endl;
		int x; cin >> x;
		cout << "? " << b + 1 << " " << a + 1 << endl;
		int y; cin >> y;

		if (x > y) {
			res[a] = x;
			S.insert(b);
		} else {
			res[b] = y;
			S.insert(a);
		}
	}
	vector<int> temp = res;
	sort(temp.begin(), temp.end());
	int elem = n;
	for (int i = 1; i < n; i++) {
		if (temp[i] != i) {
			elem = i;
			break;
		}
	}
	cout << "! ";
	for (auto r : res) {
		if (r == -1) {
			cout << elem << " ";
		} else {
			cout << r << " ";
		}
	}
	cout << endl;
	return 0;
}