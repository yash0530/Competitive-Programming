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
	int t; cin >> t;
	while (t--) {
		string sud[9];
		for (int i = 0; i < 9; i++) {
			cin >> sud[i];
		}
		sud[0][0] = (((sud[0][0] - '0') + 1) % 9) + 1 + '0';
		sud[1][3] = (((sud[1][3] - '0') + 1) % 9) + 1 + '0';
		sud[2][6] = (((sud[2][6] - '0') + 1) % 9) + 1 + '0';
		sud[3][1] = (((sud[3][1] - '0') + 1) % 9) + 1 + '0';
		sud[4][4] = (((sud[4][4] - '0') + 1) % 9) + 1 + '0';
		sud[5][7] = (((sud[5][7] - '0') + 1) % 9) + 1 + '0';
		sud[6][2] = (((sud[6][2] - '0') + 1) % 9) + 1 + '0';
		sud[7][5] = (((sud[7][5] - '0') + 1) % 9) + 1 + '0';
		sud[8][8] = (((sud[8][8] - '0') + 1) % 9) + 1 + '0';
		for (auto s : sud) {
			cout << s << endl;
		}
	}	    
    return 0;
}
