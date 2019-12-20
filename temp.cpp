#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int CeilIndex(vector<int>& v, int l, int r, int key) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key) {
			r = m;
		} else {
			l = m;
		}
	}
	return r; 
}

vector<int> LIS(vector<int>& v) {
	int n = v.size();
	vector<int> tail(n, 0), tail_index(n, -1), res(n, -1);
	int length = 1;
	tail[0] = v[0];
	tail_index[0] = 0;
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < tail[0]) {
			tail[0] = v[i];
			tail_index[0] = i;
		}
		else if (v[i] > tail[length - 1]) {
			tail[length++] = v[i];
			tail_index[length - 1] = i;
			res[i] = tail_index[length - 2];
		} 
		else {
			int x = CeilIndex(tail, -1, length - 1, v[i]);
			tail[x] = v[i];
			tail_index[x] = i;
			if (x) res[i] = tail_index[x - 1];
		}
	}

	// return length; 
	vector<int> lis;
	int x = tail_index[length - 1];
	while (res[x] != -1) {
		lis.push_back(x);
		x = res[x];
	}
	lis.push_back(x);
	reverse(lis.begin(), lis.end());
	return lis;
}

int32_t main() { fastio;
    int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> lis = LIS(arr);
	deba(lis);
    return 0;
}