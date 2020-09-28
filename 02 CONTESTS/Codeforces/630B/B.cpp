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

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
    	vector<int> ps = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    	int arr[n], res[n];
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    		for (int j = 0; j < 11; j++) {
    			if ((arr[i] % ps[j]) == 0) {
    				res[i] = j;
    			}
    		}
    	}
    	vector<int> mapping(11, -1);
    	int curr = 1;
    	for (int i = 0; i < n; i++) {
    		if (mapping[res[i]] == -1) {
    			mapping[res[i]] = curr;
    			res[i] = curr;
    			curr++;
    		} else {
    			res[i] = mapping[res[i]];
    		}
    	}
    	cout << curr - 1 << endl;
    	for (auto r : res) {
    		cout << r << " ";
    	} cout << endl;
    }
    return 0;
}
