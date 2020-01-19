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
#define pout cout << fixed << setprecision(1)

int32_t main() { fastio;
    int n;
    cin>>n;

    vector<pair<double,double> > arr(n);
    double a , b;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        arr[i].first = min(a,b);
        arr[i].second = max(a,b);
    }

    sort(arr.begin(), arr.end());

    vector<double> pref(n);
    pref[n-1] = 0;

    for(int i = n-2; i>=0 ;i--){
        pref[i] = max(arr[i+1].second, pref[i+1]);
    }

    double ans = 0;
    for(int i = 0; i< n; i++){
        ans = max(ans, arr[i].first * arr[i].second / 2);
        ans = max(ans, arr[i].first * min(arr[i].second, pref[i]));
    }

    pout << ans << endl;
    return 0;
}