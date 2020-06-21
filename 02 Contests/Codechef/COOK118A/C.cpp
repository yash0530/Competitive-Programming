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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n;
const int maxN = 1e5 + 5;
int tree[maxN], arr[maxN];

void update(int index, int val) {
    while (index <= n) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

void co_comp() {
	int temp[n];
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}
	sort(temp, temp + n);
	map<int, int> M;
	int curr = 1;
	for (int i = 0; i < n; i++) {
		if (M.find(temp[i]) == M.end()) {
			M[temp[i]] = curr++;
		}
	}
	for (int i = 0; i < n; i++) {
		arr[i] = M[arr[i]];
	}
}

int getCount(int mid) {
	int high = 0, count = 0, cum = 0;
	for (int i = 0; i < n; i++) {
		while ((high < n) and (mid >= cum)) {
			update(arr[high], 1);
			high++;
			cum += read(n) - read(arr[high]);
		}
 		cum -= read(arr[i] - 1);
 		if (high != n) {
 			if (arr[i] > arr[high]) {
 				cum--;
 			}
 		}
		count += high - i;
		update(arr[i], -1);
	}
	return count;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		co_comp();

		int B = n * (n + 1) / 2;
		int val = (B + 1) / 2;
		int low = 0, high = 1e18;
		int res = 0;

		while (low <= high) {
			int mid = (low + high) / 2;
			int count = getCount(mid);
		
			if (count >= val) {
				high = mid - 1;
				res = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
