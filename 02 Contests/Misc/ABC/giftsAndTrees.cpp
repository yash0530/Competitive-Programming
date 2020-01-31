#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

void dfs(vector<vector<ll> > &graph, ll root, vector<bool> &visited, vector<ll> &path, vector<ll> &hasShop, ll &ans){
    if(visited[root]){
        return;
    }
    visited[root] = true;
    path.pb(root);
    for(ll child: graph[root]){
        dfs(graph, child, visited, path, hasShop, ans);
    }
    for(ll i=0; i<path.size()-2; i++){
        if(!hasShop[path[i]] && !hasShop[path[i+1]] && hasShop[path[i+2]]){
            hasShop[path[i]] = true;
            ans+=1;
        }
        else if(hasShop[path[i]] && !hasShop[path[i+1]] && !hasShop[path[i+2]]){
            hasShop[path[i+2]] = true;
            ans+=1;
        }
        else if(!hasShop[path[i]] && !hasShop[path[i+1]] && !hasShop[path[i+2]]){
            hasShop[path[i+1]] = true;
            ans+=1;
        }
    }
    path.pop_back();
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll> > graph(n);
        vector<ll> hasShop(n, 0);
        for(ll i=0; i<n; i++){
            cin>>hasShop[i];
        }
        for(ll i=0; i<n-1; i++){
            ll u, v;
            cin>>u>>v;
            u--; v--;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vector<ll> path;
        vector<bool> visited(n, false);
        ll ans = 0;
        dfs(graph, 0, visited, path, hasShop, ans);
        cout<<ans<<"\n";
    }
    return 0;
}