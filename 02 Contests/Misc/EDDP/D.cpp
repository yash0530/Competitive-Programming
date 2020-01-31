#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int H[101][100001];

int knapSack(int *vals, int *wgs, int n, int w) {
    if (n < 0) return 0;
    if (w == 0) return 0;

    if (H[n][w] != -1) {
        return H[n][w];
    }
    int res = knapSack(vals, wgs, n - 1, w);
    if (w >= wgs[n]) {
        res = max(res, knapSack(vals, wgs, n - 1, w - wgs[n]) + vals[n]);
    }
    H[n][w] = res;
    return res;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;
    int vals[n], wgs[n];
    for (int i = 0; i < n; i++) {
        cin >> wgs[i] >> vals[i];
    }
    memset(H, -1, sizeof H);
    cout << knapSack(vals, wgs, n - 1, w) << endl;

    return 0;
}