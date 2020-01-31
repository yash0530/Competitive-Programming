#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int CeilIndex(vector<int>& v, int l, int r, int key) 
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key) {
            r = m;
        } else {
            l = m;
        }
    }
    return r; 
}

int lis(vector<int>& v) 
{
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0]) {
            tail[0] = v[i];
        } else if (v[i] > tail[length - 1]) {
            tail[length++] = v[i];
        } else {
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }
    }
    return length; 
} 

int32_t main() { fastio;
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    vector<int> a(k1), b(k2), c(k3);
    for (int i = 0; i < k1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < k3; i++) {
        cin >> c[i];
    }
    int n = k1 + k2 + k3;
    vector<int> arr(n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int j = 0;
    for (int i = 0; i < k1; i++, j++) {
        arr[j] = a[i];
    }
    for (int i = 0; i < k2; i++, j++) {
        arr[j] = b[i];
    }
    for (int i = 0; i < k3; i++, j++) {
        arr[j] = c[i];
    }
    cout << n - lis(arr) << endl;
    return 0;
}