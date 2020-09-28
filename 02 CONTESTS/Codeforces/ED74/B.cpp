#include <bits/stdc++.h>
typedef long long int ll;
#define deb(x) cout << #x << " => " << x << endl
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q; cin >> q;
    while (q--) {
        ll n, r; cin >> n >> r;
        set<ll> s;
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            s.insert(x);
        }
        vector<ll> arr(s.begin(), s.end());
        reverse(arr.begin(), arr.end());

        ll count = 0, offset = 0, i = 0;
        while (i < (ll) arr.size()) {
            if (arr[i] + offset > 0) {
                count++;
                offset -= r;
            }
            i++;
        }

        cout << count << endl;
    }

    return 0;
}