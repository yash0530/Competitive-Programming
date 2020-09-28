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

int32_t main() { fastio;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        vector<int>dp_odd(n);
        vector<int>dp_even(n);

        dp_odd[0] = (a[0] & 1) ? a[0] : 0;
        dp_even[0] = (!(a[0] & 1)) ? a[0] : 0;
        for(int i = 1 ; i < n ; i++){
            if(a[i] % 2 == 1){
                dp_even[i] = dp_even[i-1];
                dp_odd[i] = max(((i-k - 1 >= 0) ? dp_odd[i-k-1] : 0) + a[i], dp_odd[i - 1]);
            }
            else{
                dp_odd[i] = dp_odd[i-1];
                dp_even[i] = max(((i-k - 1 >= 0) ? dp_even[i-k-1] : 0) + a[i], dp_even[i - 1]);
            }
        }
        cout<<dp_even[n - 1] + dp_odd[n - 1]<<endl;
    }
    return 0;
}