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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // brute force solution O(n^2)
    for (int i = 0; i < n; i++) {
        int count = 1, max_elem = arr[i]; bool broken = false;
        for (int j = i + 1, k = 0; k < 2 * (n - 1); j++, k++) {
            if (max_elem > (2 * arr[j % n])) {
                broken = true;
                break;
            }
            max_elem = max(max_elem, arr[j % n]);
            count++;
        }
        if (!broken) cout << -1 << " ";   
        else cout << count << " ";
    }
    cout << endl;

    // optimal solution
    int min_elem = *min_element(arr.begin(), arr.end());
    int max_elem = *max_element(arr.begin(), arr.end());

    if (max_elem <= 2 * min_elem) {
        for (int i = 0; i < n; i++) {
            cout << -1 << " ";
        } cout << endl;
    } else {
        
    }

    return 0;
}