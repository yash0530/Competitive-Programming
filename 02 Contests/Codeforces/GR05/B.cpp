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
    vector<int> enter(n), exit(n);
    for (int i = 0; i < n; i++) {
        cin >> enter[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> exit[i];
    }
    vector<bool> exited(n + 1);
    int count = 0;
    int i = 0, j = 0;
    while (i < n and j < n) {
        if (enter[i] == exit[j]) {
            i++; j++;
        } else if (exited[enter[i]]) {
            i++;
        } else {
            count++;
            exited[exit[j]] = true;
            j++;
        }
    }
    cout << count << endl;
    return 0;
}