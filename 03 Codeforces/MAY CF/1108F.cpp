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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

class WeightedUF {
    private:
        vector<int> arr;
        vector<int> size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            arr = vector<int>(v + 1);
            size = vector<int>(v + 1);
            for (int i = 0; i <= v; i++) {
                size[i] = 1;
                arr[i] = i;
            }
        }

        bool _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            if (rootA == rootB) return false;
            
            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            return true;
        }

        bool _find(int a, int b) {
            return __root(a) == __root(b);
        }
};

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	WeightedUF uf(n + 1);
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.pb({ w, u, v });
	}
	sort(edges.begin(), edges.end());
	int ans = 0;
	for (int i = 0; i < m; ) {
		int j = i;
		while (j < m and edges[i][0] == edges[j][0]) j++;
		int cnt = j - i;
		for (int k = i; k < j; k++) {
			cnt -= uf._find(edges[k][1], edges[k][2]);
		}
		for (int k = i; k < j; k++) {
			cnt -= uf._union(edges[k][1], edges[k][2]);
		}
		ans += cnt;
		i = j;
	}
	cout << ans << endl;
	return 0;
}
