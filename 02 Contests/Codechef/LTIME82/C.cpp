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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n;
const int maxN = 505, maxK = 5e7 + 5;
int arr[maxN], res[maxN];
pii pairs[maxN];
vector<bitset<maxN>> matRow(maxN), matCol(maxN);

void mat_mul(vector<bitset<maxN>> &M1, vector<bitset<maxN>> &M2) {
	vector<bitset<maxN>> temp(maxN);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = (M1[i] & M2[j]).count() & 1;
		}
	}
	M1 = temp;
}

void exp(int k) {
	vector<bitset<maxN>> temp = mat; k--;
	while (k) {
		if (k & 1) {
			mat_mul(temp, mat);
		}
		mat_mul(mat, mat);
		k >>= 1;
	}
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> pairs[i].fs >> pairs[i].sc;
			pairs[i].fs--; pairs[i].sc--;
			for (int j = pairs[i].fs; j <= pairs[i].sc; j++) {
				matRow[i][j] = 1;
				matCol[j][i] = 1;
			}
		}
		exp(k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			} cout << endl;
		}
		for (int i = 0; i <= 62; i++) {
			bitset<maxN> b;
			for (int i = 0; i < n; i++) {
				b[i] = arr[i] & (1 << i);
			}
			for (int i = 0; i < n; i++) {
				if (b[i]) {
					b[i] =  (n - mat[i].count()) & 1;
				} else {
					b[i] = mat[i].count() & 1;
				}
			}
			for (int i = 0; i < n; i++) {
				if (b[i]) res[i] += (1 << i);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 0;
			}
		}
	} 
	return 0;
}
