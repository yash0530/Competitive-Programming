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

int n, d, a;
vector<pair<int, int>> arr;

int32_t main() { fastio;
    time_t start = now();

    cin >> n >> d >> a;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    int i = 0, sum = 0, res = 0;
    queue<pair<int, int>> Q;
    while (i < n) {
        int curr = arr[i].first;
        if (!Q.empty() and Q.front().first == i) {
            sum -= Q.front().second;
            Q.pop();
        }
        arr[i].second -= sum;
        if (arr[i].second <= 0) {
            i++;
            continue;
        }
        int j = i + 1;
        int bombs = 0;
        while (j < n) {
            if (curr + arr[j].first > (2 * d + 2)) {
                bombs = (arr[i].second + a - 1) / a;
                Q.push({ j, bombs * a });
                res += bombs;
                break;
            }
            j++;
        }
        if (j == n) {
            bombs = (arr[i].second + a - 1) / a;
            Q.push({ j, bombs * a });
            res += bombs;
        }
        i++;
        sum += (bombs * a);
    }
    cout << res << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}