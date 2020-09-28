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
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

const int N = 1e6 + 5;

int32_t main() { fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<bool> freq(N);
    vector<bool> present(N);
    vector<int> res;
    int prev = 0, count = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (freq[arr[i]] or present[arr[i]]) {
                possible = false;
                break;
            } else {
                freq[arr[i]] = true;
                present[arr[i]] = true;
                count++;
            }
        } else {
            if (!present[-arr[i]]) {
                possible = false;
                break;
            }
            present[-arr[i]] = false;
            count--;
            if (count == 0) {
                res.push_back(i - prev + 1);
                for (int j = prev; j <= i; j++) {
                    if (arr[j] > 0) {
                        freq[arr[j]] = false; 
                    }
                }
                prev = i + 1;
            }
        }
    }
    if (accumulate(res.begin(), res.end(), 0) != n) {
        possible = false;
    }
    if (possible) {
        cout << res.size() << endl;
        for (auto r : res) {
            cout << r << " ";
        } cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}