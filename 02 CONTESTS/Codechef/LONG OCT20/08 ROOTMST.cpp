#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

const int maxN = 10;
int n, m;
int ans[maxN];
vector<array<int, 3>> curr;
vector<array<int, 3>> edges;

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

bool isTree(vector<array<int, 3>> curr) {
	WeightedUF uf(n);
	for (auto e : curr) {
		if (!uf._union(e[0], e[1])) {
			return false;
		}
	}
	return true;
}

void doStuff(int pos) {
	if (size(curr) == (n - 1)) {
		if (isTree(curr)) {
			int count = 0, sum = 0;
			for (auto e : curr) {
				if ((e[0] == 1) or (e[1] == 1)) {
					count++;
				}
				sum += e[2];
			}
			ans[count] = min(ans[count], sum);
			if (count == 3) {
				debm(curr);
			}
		}
		return;
	}
	if (pos < m) {
		doStuff(pos + 1);
		curr.pb(edges[pos]);
		doStuff(pos + 1);
		curr.pop_back();
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		array<int, 3> edge;
		for (int j = 0; j < 3; j++) {
			cin >> edge[j];
		}
		edges.pb(edge);
	}
	for (int i = 0; i < maxN; i++) {
		ans[i] = INF;
	}
	doStuff(0);
	for (int i = 1; i < n; i++) {
		cout << ans[i] << " ";
	} cout << endl;
	return 0;
}