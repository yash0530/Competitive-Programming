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
    	int n, sum = 0; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		int max_so_far = arr[0]; 
	   	int curr_max = arr[0]; 
	   	for (int i = 1; i < n - 1; i++) { 
	        curr_max = max(arr[i], curr_max + arr[i]); 
	        max_so_far = max(max_so_far, curr_max); 
	   	}

	   	int m = max_so_far;

	   	max_so_far = arr[1]; 
	   	curr_max = arr[1]; 
	   	for (int i = 2; i < n; i++) { 
	        curr_max = max(arr[i], curr_max + arr[i]); 
	        max_so_far = max(max_so_far, curr_max); 
	   	}

	   	m = max(max_so_far, m);
	   	if (sum > m) {
	   		cout << "YES" << endl;
	   	} else {
	   		cout << "NO" << endl;
	   	}
    }
    return 0;
}
