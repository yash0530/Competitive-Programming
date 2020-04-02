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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;}

const int maxN = 1e5 + 5;
int x, y, a, b, c;
int p[maxN], q[maxN], r[maxN];

int32_t main() { fastio;
    
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; i++) {
    	cin >> p[i];
    }
    for (int i = 0; i < b; i++) {
    	cin >> q[i];
    }
    for (int i = 0; i < c; i++) {
    	cin >> r[i];
    }
    sort(p, p + a, greater<int>());
    sort(q, q + b, greater<int>());
    sort(r, r + c, greater<int>());

    int lastA = min(a - 1, x - 1);
    int lastB = min(b - 1, y - 1);
    int firstC = 0;
    int curr = 0;

    if (x > a) {
    	for (auto al : p) {
    		curr += al;
    	}
    	for (int i = 0; i < (x - a); i++) {
    		curr += r[i];
    		firstC++;
    	}
    } else {
    	for (int i = 0; i < x; i++) {
    		curr += p[i];
    	}
    }

    if (y > b) {
    	for (auto al : q) {
    		curr += al;
    	}
    	for (int i = firstC; i < (y - b); i++) {
    		curr += r[i];
    		firstC++;
    	}
    } else {
    	for (int i = 0; i < y; i++) {
    		curr += q[i];
    	}
    }

    for (int i = firstC; i < c; i++) {
    	if (lastA < 0 and lastB < 0) {
    		break;
    	} else if (lastA < 0 and lastB >= 0) {
    		if (r[i] < q[lastB]) {
    			break;
    		} else {
    			curr -= q[lastB];
    			curr += r[i];
    			lastB--;
    		}
    	} else if (lastA >= 0 and lastB < 0) {
    		if (r[i] < p[lastA]) {
    			break;
    		} else {
    			curr -= p[lastA];
    			curr += r[i];
    			lastA--;
    		}
    	} else if (p[lastA] > q[lastB]) {
    		if (r[i] < q[lastB]) {
    			break;
    		} else {
    			curr -= q[lastB];
    			curr += r[i];
    			lastB--;
    		}
    	} else {
    		if (r[i] < p[lastA]) {
    			break;
    		} else {
    			curr -= p[lastA];
    			curr += r[i];
    			lastA--;
    		}
    	}
    }

    cout << curr << endl;

    return 0;
}