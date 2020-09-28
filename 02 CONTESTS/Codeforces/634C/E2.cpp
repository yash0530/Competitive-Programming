#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

const int maxN = 2e5 + 5;
int freq[maxN][205];

int32_t main() { fastio;
	int t; cin >> t;
	memset(freq, 0, sizeof freq);
	while (t--) {
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int j = 0; j < 205; j++) {
			int last = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] == j) {
					last++;
				}
				freq[i][j] = last;
			}
		}
		
		set<int> unique;
		for (auto a : arr) {
			unique.insert(a);
		}
		int res = 0;
		for (auto u : unique) {
			int low = 0, high = n - 1;
			int curr = 0;
			int now = 0;	
			while (low < high) {
				int th = 0;
				while (low < high) {
					if (arr[low] == u) {
						now++;
						th++;
						break;
					}
					low++;
				}
				while (low < high) {
					if (arr[high] == u) {
						now++;
						th++;
						break;
					}
					high--;
				}
				if (th == 2) {
					int left = low + 1, right = high - 1;
					int add = 0;
					if (left < n and high >= 0) {
						for (int i = 0; i < 205; i++) {
							add = max(add, freq[right][i] - freq[left - 1][i]);
						}
					}
					curr = max(curr, now + add);
					low++;
					high--;
				}
			}
			res = max(curr, res);
		}
		cout << max(res, 1) << endl;
	}	    
    return 0;
}