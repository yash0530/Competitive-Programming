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
#define _all(aa) aa.begin(), aa.end()

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
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> okay(n + 1);
	vector<int> freq(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> okay[i];
		freq[okay[i]]++;
	}
	vector<int> res(m + 1, -1);
	for (int i = 1; i <= m; i++) {
		if (freq[i] == 1) {
			res[i] = 0;
		}
	}
	WeightedUF uf(n);

	auto check = [&](int v1) {
		int have = -1;
		for (int i = 1; i <= n; i++) {
			if (okay[i] == v1) {
				if (have == -1) {
					have = i;
				} else {
					if (!uf._find(i, have)) return false;
				}
			}
		}
		return true;
	};

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (uf._union(a, b)) {
			int v1 = okay[a];
			int v2 = okay[b];		
			if (res[v1] == -1 and check(v1)) {
				res[v1] = i + 1;
			}
			if (res[v2] == -1 and check(v2)) {
				res[v2] = i + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << res[i] << endl;
	}
	return 0;
}