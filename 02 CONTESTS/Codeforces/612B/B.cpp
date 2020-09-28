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

string XOR(string a, string b) {
	int x = a.length();
	string res;
	for (int i = 0; i < x; i++) {
		if (a[i] == b[i]) {
			res.push_back(a[i]);
		} else {
			if (a[i] == 'E' and b[i] == 'S') {
				res.push_back('T');
			} else if (a[i] == 'E' and b[i] == 'T') {
				res.push_back('S');
			} else if (a[i] == 'S' and b[i] == 'E') {
				res.push_back('T');
			} else if (a[i] == 'S' and b[i] == 'T') {
				res.push_back('E');
			} else if (a[i] == 'T' and b[i] == 'E') {
				res.push_back('S');
			} else if (a[i] == 'T' and b[i] == 'S') {
				res.push_back('E');
			}
		}	
	}
	return res;
}

int32_t main() { fastio;
	
	int n, k;
	cin >> n >> k;
	map<string, int> H;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		arr[i] = s;
		H[s]++;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string t = XOR(arr[i], arr[j]);
			if (t.compare(arr[i]) == 0) {
				count += H[t] - 2;
			} else {
				count += H[t];
			}
		}
	}
	cout << count / 3 << endl;

    return 0;
}
