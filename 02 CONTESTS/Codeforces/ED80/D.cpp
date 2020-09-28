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
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int n, m;
vector<vector<int>> arr;
int x, y;

bool poss(int val) {
    set<int> nums;
    map<int, int> H;
    for (int k = 0; k < n; k++) {
        int num = 0;
        for (int i = 0; i < m; i++) {
            if (arr[k][i] >= val) {
                num = num | (1 << i);
            }
        }
        nums.insert(num);
        H[num] = k + 1;
    }
    for (auto a : nums) {
        for (auto b : nums) {
            if ((a | b) == ((1 << m) - 1)) {
                x = H[a]; y = H[b];
                return true;
            }
        }
    }
    return false;
}

int32_t main() { fastio;
    time_t start = now();

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int low = 0, high = 1e9, res = -1;
    int a = -1, b = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (poss(mid)) {
            res = mid;
            a = x, b = y;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << a << " " << b << endl;

    cerr << "TIME => " << now() - start << endl;
    return 0;
}