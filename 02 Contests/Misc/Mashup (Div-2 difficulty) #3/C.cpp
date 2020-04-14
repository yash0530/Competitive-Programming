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

int x;
vector<int> res(105);


void process(string str, string s) { 
    for (int i = 0; i < size(str); i++) { 
        if (str.substr(i, size(s)) == s) { 
            for (int j = i; j < (size(s) + i); j++) {
            	res[j] = 1;
            }
        } 
    } 
} 

int32_t main() { fastio;
	int n; cin >> n;
	vector<string> arr(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
	}
	cin >> s;
	char t; cin >> t;
	string temp = s;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	x = size(s);
	for (int i = 0; i < n; i++) {
		process(temp, arr[i]);
	}

	for (int i = 0; i < x; i++) {
		if (res[i]) {
			if (tolower(s[i]) != t) {
				if (isupper(s[i])) {
					s[i] = toupper(t);
				} else {
					s[i] = t;
				}
			} else {
				if (t == 'a') {
					if (isupper(s[i])) {
						s[i] = 'B';
					} else {
						s[i] = 'b';
					}
				} else {
					if (isupper(s[i])) {
						s[i] = 'A';
					} else {
						s[i] = 'a';
					}
				}
			}
		}
	}
	cout << s << endl;
    return 0;
}
