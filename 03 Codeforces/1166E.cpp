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
	int m, n;
	cin >> m >> n;
	vector<vector<int>> arr(m);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		arr[i] = vector<int>(x);
		for (int j = 0; j < x; j++) {
			cin >> arr[i][j];
		}
		sort(arr[i].begin(), arr[i].end());
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int a = 0, b = 0;
			bool found = false;
			while(a < size(arr[i]) and b < size(arr[j])) {
				if (arr[i][a] == arr[j][b]) {
					found = true;
					break;
				}
				if (arr[i][a] > arr[j][b]) {
					b++;
				} else {
					a++;
				}
			}
			if (!found) {
				cout << "impossible" << endl;
				exit(0);
			}
		}
	}
	cout << "possible" << endl;
    return 0;
}
