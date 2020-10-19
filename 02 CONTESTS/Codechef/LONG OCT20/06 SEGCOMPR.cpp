#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 998244353LL
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

int result;
int val(int a, int b) {
	a = a ^ b;
	while (a) {
		if ((a & (a - 1)) == 0) {
			break;
		}
		a -= a & -a;
	}
	return a;
}

void doStuff(vector<int> arr) {
	if (size(arr) <= 1) {
		result = min(result, arr[0]);
		return;
	}
	for (int i = 0; i < size(arr); i++) {
		for (int j = i + 1; j < size(arr); j++) {
			vector<int> res;
			for (int k = 0; k < size(arr); k++) {
				if ((i != k) and (j != k))
					res.pb(arr[k]);
			}
			res.pb(val(arr[i], arr[j]));
			doStuff(res);
		}
	}
}

int getVal(vector<int> arr) {
	result = INF;
	doStuff(arr);
	return result;
}

int32_t main() { fastio;
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> freq(32);
		int sz = 0;
		for (int j = i; j < n; j++) {
			sz++;
			int count = 0, temp = arr[j];
			while (temp) {
				if (temp & 1) {
					freq[count]++;
				}
				temp /= 2;
				count++;
			}
			if (sz == 1) {
				ans = (ans + arr[j]) % HELL;
			} else {
				for (int bit = 31; bit >= 0; bit--) {
					if (freq[bit] and (freq[bit] % 2 == 0) and (freq[bit] == sz)) {
						vector<int> temp(arr.begin() + i, arr.begin() + j + 1);
						ans = (ans + getVal(temp)) % HELL;
						break;
					}
					if (freq[bit] and (freq[bit] % 2 == 0)) {
						if ((2 * freq[bit]) > sz) { 
							vector<int> temp(arr.begin() + i, arr.begin() + j + 1);
							ans = (ans + getVal(temp)) % HELL;
						}
						break;
					}
					if (freq[bit] & 1) {
						ans = (ans + (1 << bit)) % HELL;
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}