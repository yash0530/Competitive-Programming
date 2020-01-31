#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int getLen(int *hash, vector<vector<int>> &rev, int vertex) {
    if (rev[vertex].size() == 0) {
        return 0;
    }
    if (hash[vertex]) {
        return hash[vertex];
    }
    int maxLen = 0;
    for (auto r : rev[vertex]) {
        maxLen = max(maxLen, getLen(hash, rev, r) + 1);
    }
    hash[vertex] = maxLen;
    return maxLen;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int *hash = new int[n];
    memset(hash, false, sizeof false);

    vector<vector<int>> rev(n);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        rev[b].push_back(a);
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, getLen(hash, rev, i));
    }
    cout << maxLen << endl;

    return 0;
}