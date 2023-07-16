#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
vector<int>	adj[maxN];
vector<int> deg(maxN);

vector<int> curr_comp;
vector<int> visited(maxN);

void dfs(int p) {
	curr_comp.push_back(p);
	visited[p] = true;
	for (auto x : adj[p]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++; deg[b]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			curr_comp.clear();
			dfs(i);
			bool poss = true;
			for (auto x : curr_comp) {
				if (deg[x] != 2) {
					poss = false;
				}
			}
			ans += poss;
		}
	}
	cout << ans << endl;
}