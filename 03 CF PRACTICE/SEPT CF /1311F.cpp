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

vector<int> cocomp(vector<int> arr) {
	map<int, int> MP;
	vector<int> temp = arr;
	int n = size(arr);
	sort(temp.begin(), temp.end());
	for (int i = 0, curr = 0; i < n; i++) {
		if (MP.find(temp[i]) == MP.end()) {
			MP[temp[i]] = ++curr;
		}
	}
	vector<int> res;
	for (auto a : arr) {
		res.pb(MP[a]);
	}
	return res;
}

int n;
const int maxN = 2e5 + 5;
int t1[maxN], t2[maxN];

void update(int index, int val, int *tree) {
    while (index <= n) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index, int *tree) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

int32_t main() { fastio;
	cin >> n;
	vector<int> arr(n), brr(n);
	for (auto &a : arr) cin >> a;
	for (auto &b : brr) cin >> b;
	
	brr = cocomp(brr);
	vector<pii> events(n);
	for (int i = 0; i < n; i++) {
		events[i] = { arr[i], brr[i] };
	}
	sort(events.begin(), events.end());
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (read(events[i].sc, t1) * events[i].fs - read(events[i].sc, t2));
		update(events[i].sc, 1, t1);
		update(events[i].sc, events[i].fs, t2);
	}
	cout << res << endl;
	return 0;
}