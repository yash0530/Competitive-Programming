#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const int N = 200 * 1000 + 13;
const li INF64 = 1e18;

int n, m;
li a[N];
vector<pair<int, li>> g[N];

li dist[N];

void Dijkstra(){
	set<pair<li, int>> q;
	forn(i, n){
		dist[i] = a[i];
		q.insert({dist[i], i});
	}
	
	while (!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		
		for (auto it : g[v]){
			int u = it.first;
			li w = it.second;
			
			if (dist[u] > dist[v] + w){
				q.erase({dist[u], u});
				dist[u] = dist[v] + w;
				q.insert({dist[u], u});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	forn(_, m){
		int f, t;
		li w;
		scanf("%d%d%lld", &f, &t, &w);
		--f, --t;
		w *= 2;
		g[f].push_back({t, w});
		g[t].push_back({f, w});
	}
	forn(i, n){
		scanf("%lld", &a[i]);
	}
	
	Dijkstra();
	forn(i, n)
		printf("%lld ", dist[i]);
	puts("");
	return 0;
}