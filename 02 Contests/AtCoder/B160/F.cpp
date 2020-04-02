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

int n;
const int maxN = 5e5 + 5;
vector<int> adj[maxN];

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

struct event {
    int pos, type, ind;
    bool operator<(const event &a) {
        return make_pair(pos, type) < make_pair(a.pos, a.type);
    }
};

int32_t main() { fastio;
    
    cin >> n;
	vector<event> events;
	pair<int, int> arr[n + 1];
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		arr[i] = { a, b };
		events.push_back({ b, 1, i });
		events.push_back({ a, 2, i });
	}
	sort(events.begin(), events.end());

	WeightedUF uf(n + 5);
	set<event> evs;
	int total = 0;
	for (auto e : events) {
		if (e.type == 1) {
			const event x = { arr[e.ind].first, 2, e.ind };
            auto alpha = evs.find(x);
            evs.erase(alpha);
		} 
    // else {
	// 		total += evs.size();
	// 		for (auto x : evs) {
	// 			if (uf._find(e.ind, x.ind)) {
	// 				cout << "NO" << endl;
	// 				return 0;
	// 			}
	// 			uf._union(e.ind, x.ind);
	// 		}
	// 		evs.insert(e);
	// 	}
	// 	if (total >= n) {
	// 		cout << "NO" << endl;
	// 		return 0;
	// 	}
	}
	cout << "YES" << endl;
    return 0;
}
