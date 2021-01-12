#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		int count = 0;
		vector<int> state(n, 0);
		for (int i = 1; i < (n - 1); i++) {
			if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
				state[i] = 1;
				count++;
			}
			if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1]) {
				state[i] = 1;
				count++;
			}
		}
		int rem = 0;
		for (int i = 0; i < n; i++) {
			// change it to i - 1
			int curr = 0;
			int val = arr[i];
			if (i) {
				arr[i] = arr[i - 1];
				if (state[i] != 0) {
					curr++;
				}
				if (i and state[i - 1] != 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
					} else {
						curr++;
					}
				}

				if (i != (n - 1) and state[i + 1] != 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
					} else {
						curr++;
					}
				}

				if ((i - 1) > 0 and state[i - 1] == 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
						curr--;
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
						curr--;
					}
				}

				if ((i + 1) < (n - 1) and state[i + 1] == 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
						curr--;
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
						curr--;
					}
				}

				rem = max(rem, curr);
			}

			curr = 0;
			// change it to i + 1
			if (i != (n - 1)) {
				arr[i] = arr[i + 1];
				if (state[i] != 0) {
					curr++;
				}
				if (i and state[i - 1] != 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
					} else {
						curr++;
					}
				}

				if (i != (n - 1) and state[i + 1] != 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
					} else {
						curr++;
					}
				}


				if ((i - 1) > 0 and state[i - 1] == 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
						curr--;
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
						curr--;
					}
				}

				if ((i + 1) < (n - 1) and state[i + 1] == 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
						curr--;
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
						curr--;
					}
				}

				rem = max(rem, curr);
			}

			curr = 0;
			// change it to i + 1
			if (i != (n - 1) and i) {
				arr[i] = (arr[i + 1] + arr[i - 1]) / 2;
				if (state[i] != 0) {
					curr++;
				}
				if (i and state[i - 1] != 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
					} else {
						curr++;
					}
				}

				if (i != (n - 1) and state[i + 1] != 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
					} else {
						curr++;
					}
				}

				if ((i - 1) > 0 and state[i - 1] == 0) {
					if (arr[i - 1] > arr[i] and arr[i - 1] > arr[i - 2]) {
						curr--;
					} else if (arr[i - 1] < arr[i] and arr[i - 1] < arr[i - 2]) {
						curr--;
					}
				}

				if ((i + 1) < (n - 1) and state[i + 1] == 0) {
					if (arr[i + 1] > arr[i + 2] and arr[i + 1] > arr[i]) {
						curr--;
					} else if (arr[i + 1] < arr[i + 2] and arr[i + 1] < arr[i]) {
						curr--;
					}
				}
				
				rem = max(rem, curr);
			}			

			arr[i] = val;
		}
		cout << count - rem << endl;
	}
	return 0;
}