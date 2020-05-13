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

        int _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            int sa = size[rootA], sb = size[rootB];

            int update = ((sa + sb) * (sa + sb - 1) / 2) - (sa * (sa - 1) / 2) - (sb * (sb - 1) / 2);

            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            return update;
        }

        bool _find(int a, int b) {
            return __root(a) == __root(b);
        }
};

int32_t main() { fastio;
	int n, m, u, v, w;
	cin >> n >> m;
	vector<vector<int>> edges(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		edges[i] = { w, u, v };
	}
	WeightedUF uf(n);
	sort(edges.begin(), edges.end());
	vector<int> edgs(n - 1), tots(n);
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += uf._union(edges[i][1], edges[i][2]);
		edgs[i] = edges[i][0];
		tots[i + 1] = tot;
	}
	while (m--) {
		int x; cin >> x;
		int alpha = upper_bound(edgs.begin(), edgs.end(), x) - edgs.begin();
		cout << tots[alpha] << " ";
	} cout << endl;
	return 0;
}
