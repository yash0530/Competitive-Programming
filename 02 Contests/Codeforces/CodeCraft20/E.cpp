#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, p, k;
const int maxN = 1e5 + 5, maxK = 1e5 + 5, maxP = 8;
pair<int, int> arr[maxN];
int mat[maxN][maxP], mat2[maxN][maxP], dp[maxN][(1 << maxP)];

int res(int index = 0, int mask = 0) {

	if (dp[index][mask] != -1) {
		return dp[index][mask];
	}

	int c = __builtin_popcount(mask);
	int aud = index - c;
	if (index == n) {
		if (c == p) {
			return 0;
		} else {
			return -INF;
		}
	}
	int curr = 0;
	if (aud < k) {
		curr = res(index + 1, mask) + arr[index].first;
	}
	if (c < p) {
		for (int i = 0; i < p; i++) {
			if ((mask & (1 << i)) == 0) {
				curr = max(curr, res(index + 1, mask | (1 << i)) + mat2[index][i]);
			}
		}
		curr = max(curr, res(index + 1, mask));
	}
	dp[index][mask] = curr;
	return curr;
}

int32_t main() { fastio;
    time_t start = now();

    memset(dp, -1, sizeof dp);

    cin >> n >> p >> k;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i].first;
    	arr[i].second = i;
    }
    sort(arr, arr + n, greater<pair<int, int>>());
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < p; j++) {
    		cin >> mat[i][j];
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < p; j++) {
    		mat2[i][j] = mat[arr[i].second][j];
    	}
    }
    cout << res() << endl;


    cerr << "TIME => " << now() - start << endl;
    return 0;
}