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

vector<int> prefix_function(vector<int> &s) {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	int x, n, m; cin >> x >> n;
    	if (n > 1) {
	    	int arr[n];
	    	vector<int> diff;
	    	for (int i = 0; i < n; i++) {
	    		cin >> arr[i];
	    		if (i) {
	    			diff.push_back(arr[i] - arr[i - 1]);
	    		}
	    	} diff.push_back(INF);
	    	cin >> m;
	    	int brr[m];
	    	for (int i = 0; i < m; i++) {
	    		cin >> brr[i];
	    		if (i) {
	    			diff.push_back(brr[i] - brr[i - 1]);
	    		}
	    	}
	    	int count = 0;
	    	vector<int> pre = prefix_function(diff);
	    	for (int i = n, j = 0; i < (int) pre.size(); i++, j++) {
	    		if (pre[i] == n - 1) {
	    			if (abs(arr[0] - brr[j - n + 2]) <= x) {
	    				count++;
	    			}
	    		}
	    	}
	    	cout << count << endl;
	    } else {
	    	int count = 0;
	    	int a, b; cin >> a;
	    	cin >> m;
	    	for (int i = 0; i < m; i++) {
	    		cin >> b;
	    		if (abs(a - b) <= x) {
	    			count++;
	    		}
	    	}
	    	cout << count << endl;
	    }
    }
    return 0;
}
