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
    for (int _ = 1; _ <= t; _++) {
    	cout << "Case #" << _ << ": ";
    	int r, c;
    	cin >> r >> c;
    	int mat[r][c];
    	for (int i = 0; i < r; i++) {
    		for (int j = 0; j < c; j++) {
    			cin >> mat[i][j];
    		}
    	}
    	int elem = INF;
    	int res = 0;
    	while (elem > 0) {
    		elem = 0;
    		vector<pair<int, int>> toDel;
    		for (int i = 0; i < r; i++) {
    			for (int j = 0; j < c; j++) {
    				if (mat[i][j]) {
	    				res += mat[i][j];
	    				int count = 0, sum = 0;
	    				int xloc = i - 1;
	    				while (xloc >= 0) {
	    					if (mat[xloc][j] > 0) {
	    						count++;
	    						sum += mat[xloc][j];
	    						break;
	    					}
	    					xloc--;
	    				}
	    				xloc = i + 1;
	    				while (xloc < r) {
	    					if (mat[xloc][j] > 0) {
	    						count++;
	    						sum += mat[xloc][j];
	    						break;
	    					}
	    					xloc++;
	    				}
	    				int yloc = j - 1;
	    				while (yloc >= 0) {
	    					if (mat[i][yloc] > 0) {
	    						count++;
	    						sum += mat[i][yloc];
	    						break;
	    					}
	    					yloc--;
	    				}
	    				yloc = j + 1;
	    				while (yloc < c) {
	    					if (mat[i][yloc] > 0) {
	    						count++;
	    						sum += mat[i][yloc];
	    						break;
	    					}
	    					yloc++;
	    				}
	    				if ((count > 0) and (sum > (count * mat[i][j]))) {
	    					elem++;
	    					toDel.push_back({ i, j });
	    				}
	    			}
    			}
    		}

    		for (auto e : toDel) {
    			mat[e.first][e.second] = 0;
    		}
    	}
    	cout << res << endl;
	}
    return 0;
}
