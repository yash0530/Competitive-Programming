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

bool lunlun(int n) {
	int last = n % 10;
	n /= 10;
	while (n) {
		int x = n % 10;
		if (abs(x - last) > 1) {
			return false;
		}
		last = x;
		n /= 10;
	}
	return true;
}

vector<string> H = {
	"99",
	"999",
	"9999",
	"99999",
	"999999",
	"9999999",
	"99999999",
	"999999999",
	"9999999999",
	"99999999999",
};

void next(string &curr) {
	if (find(H.begin(), H.end(), curr) != H.end()) {
		int x = curr.length();
		curr = "1";
		for (int i = 0; i < x; i++) {
			curr.push_back('0');
		}
		return;
	}

	int x = curr.length();
	int loc = x - 1;
	while (loc > 0) {
		if (curr[loc] > curr[loc - 1]) {
			loc--;
		} else {
			if (curr[loc] == '9') {
				loc--;
				continue;
			}
			curr[loc]++;
			loc++;
			while (loc < x) {

				curr[loc] = max((int) '0', curr[loc - 1] - 1LL);
				loc++;
			}
			return;			
		}
	}
	curr[loc]++;
	loc++;
	while (loc < x) {

		curr[loc] = max((int) '0', curr[loc - 1] - 1LL);
		loc++;
	}
}

int32_t main() { fastio;
    int k; cin >> k;
    if (k > 12) {
    	string curr = "21";
    	int loc = 13;
    	while (loc < k) {
    		next(curr);
    		loc++;
    	}
    	cout << curr << endl;
    } else {
    	cout << k << endl;
    }
    return 0;
}
