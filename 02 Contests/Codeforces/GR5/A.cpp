#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int32_t main() {
    fastio;
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i] / 2;
        sum += brr[i];
    }
    for (int i = 0; i < n; i++) {
        if (sum == 0) {
            break;
        }
        if (sum > 0) {
            if (arr[i] < 0 and abs(arr[i]) % 2 == 1) {
                brr[i]--;
                sum--;
            }
        } else {
            if (arr[i] > 0 and arr[i] % 2 == 1) {
                brr[i]++;
                sum++;
            }
        }
    }
    for (auto b : brr) {
        cout << b << endl;
    }
    return 0;
}