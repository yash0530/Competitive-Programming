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

int N, A, B, C;

vector<vector<int>> vals;
vector<int> res;

void gen(int i = 0) {
	if (i == N) {
		vals.pb(res);
		return;
	}
	for (int x = 1; x <= N; x++) {
		res.pb(x);
		gen(i + 1);
		res.pop_back();
	}
}

bool check(vector<int> &v) {
	int a = 1, b = 1, c = 0;
	int mx = v[0];
	for (int i = 1; i < N; i++) {
		if ((v[i] - mx) >= 0) {
			a++;
		}
		mx = max(v[i], mx);
	}
	mx = v.back();
	for (int i = N - 2; i >= 0; i--) {
		if ((v[i] - mx) >= 0) {
			b++;
		}
		mx = max(v[i], mx);
	}
	for (auto x : v) {
		if (x == mx) c++;
	}
	if ((a == A) and (b == B) and (c == C)) {
		return true;
	}
	return false;
}

int32_t main() { fastio;
	int t; cin >> t;
	for (int _ = 1; _ <= t; _++) {
		cout << "Case #" << _ << ": ";

		cin >> N >> A >> B >> C;

		if (N <= 5) {
			vals.clear();
			res.clear();
			gen();

			bool found = false;
			for (auto v : vals) {
				if (check(v)) {
					found = true;
					for (auto x : v) cout << x << " ";
					break;
				}
			}
			if (!found) {
				cout << "IMPOSSIBLE";
			}
		} else {
			if ((A + B - C) > N) {
				cout << "IMPOSSIBLE";
			} else if ((B == C) and (C == 1) and (A != 1)) {
				for (int i = 0; i < (A - 1); i++) {
					cout << N - 1 << " ";
				}
				for (int i = 0; i < (N - A); i++) {
					cout << 1 << " ";
				}
				cout << N;
			} else {
				vector<int> ans;
				for (int i = 0; i < (A - C); i++) {
					ans.pb(2);
				}
				int extra = N - (A + B - C);
				ans.pb(N);
				for (int i = 0; i < extra; i++) {
					ans.pb(1);
				}
				for (int i = (A - C) + 1; i < A; i++) {
					ans.pb(N);
				}
				for (int i = 0; i < (B - C); i++) {
					ans.pb(2);
				}
				if (check(ans)) {
					for (auto r : ans) cout << r << " ";
				} else {
					cout << "IMPOSSIBLE";
				}
			}	
		}
		cout << endl;
	}
	return 0;
}