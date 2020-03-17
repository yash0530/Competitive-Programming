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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, a, b, k;
vector<int> arr;
vector<int> reqd;

void res(int index, int rem) {
    if (index == n) {
        return;
    }
    int val = arr[index] % (a + b);
    if (1 <= val and val <= a) {
        reqd[index] = 0;
        res(index + 1, rem);
        return;
    }
    if (val == 0) val = (a + b);
    val -= a;
    int times = (val + a - 1) / a;
    reqd[index] = times;
    res(index + 1, rem);
}

int32_t main() { fastio;
    time_t start = now();

    cin >> n >> a >> b >> k;
    arr.resize(n);
    reqd.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    res(0, k);
    sort(reqd.begin(), reqd.end());
    int ans = 0;
    for (auto r : reqd) {
        if (r == 0) {
            ans++;
            continue;
        }
        if (r > k) {
            break;
        }
        k -= r;
        ans++;
    }
    cout << ans << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}