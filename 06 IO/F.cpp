#include <bits/stdc++.h>
using namespace std;

#define MOD (int) (1e9 + 7)

int n, m;
const int maxN = 201;
int cache[maxN][maxN][maxN];
char matrix[maxN][maxN];

int dp(int row, int col, int bal) {
	if ((row + 1) == n and (col + 1) == m) {
		return bal == 0;
	}
	if (bal < 0) {
		return 0;
	}
	int &ans = cache[row][col][bal];
	if (ans == -1) {
		ans = 0;

		// go down
		if ((row + 1) < n) {
			ans = (ans + dp(row + 1, col, bal + (matrix[row + 1][col] == '(' ? 1 : -1))) % MOD;
		}

		// go right
		if ((col + 1) < m) {
			ans = (ans + dp(row, col + 1, bal + (matrix[row][col + 1] == '(' ? 1 : -1))) % MOD;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	memset(cache, -1, sizeof cache);
	if (matrix[0][0] == '(')
		cout << dp(0, 0, 1) << endl;
	else
		cout << 0 << endl;
	return 0;
}