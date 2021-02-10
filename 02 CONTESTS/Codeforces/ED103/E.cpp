#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
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

const int maxN = 1e5 + 5;
int n;
set<int> adj[maxN];

void topoDFS(int v, vector<bool> &visited, vector<int> &res) {
    visited[v] = true;
    for (auto a : adj[v]) {
        if (!visited[a]) {
            topoDFS(a, visited, res); 
        }
    }
    res.pb(v);
}

vector<int> topoSort() {
    vector<int> res; 
    vector<bool> visited(n + 5);
    for (int i = 1; i <= n; i++) { 
        if (!visited[i]) { 
            topoDFS(i, visited, res); 
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

bool cycleDFS(int v, vector<bool> &visited, vector<bool> &recStack) { 
    if(!visited[v]) {
        visited[v] = true; 
        recStack[v] = true;
        for(auto a : adj[v]) { 
            if (!visited[a] and cycleDFS(a, visited, recStack)) {
                return true; 
            }
            else if (recStack[a]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false; 
}

bool hasCycle() {
    vector<bool> visited(n + 5), recStack(n + 5);
    for(int i = 1; i <= n; i++) {
        if (cycleDFS(i, visited, recStack)) {
            return true; 
        }
    }
    return false; 
}

signed main() { fastio;
	int m, k;
	cin >> n >> m >> k;
	map<string, vector<int>> mp;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		mp[s].pb(i);
	}
	bool poss = true;
	for (int i = 0; i < m; i++) {
		cin >> s;
		int val; cin >> val;
		bool found = false;
		vector<int> okays;
		for (int mask = 0; mask < (1LL << k); mask++) {
			string now = "";
			for (int i = 0; i < k; i++) {
				if (mask & (1LL << i)) {
					now.pb(s[i]);
				} else {
					now.pb('_');
				}
			}
			if (mp.find(now) != mp.end()) {
				for (auto x : mp[now]) {
					okays.pb(x);
					if (x == val) {
						found = true;
					}
				}
			}
		}
		if (!found) {
			poss = false;
			break;
		} else {
			for (auto x : okays) {
				if (val == x) continue;
				adj[val].insert(x);
				if (adj[x].find(val) != adj[x].end()) {
					poss = false;
					break;
				}
			}
		}
		if (!poss) {
			break;
		}
	}
	if (poss and !hasCycle()) {
		cout << "YES" << endl;
		auto ts = topoSort();
		for (auto t : ts) {
			cout << t << " ";
		} cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}