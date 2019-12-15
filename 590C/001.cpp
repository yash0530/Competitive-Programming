#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q; cin >> q;
    while (q-- > 0) {
        ll n; cin >> n;
        ll sum = 0, temp;
        for (ll i = 0; i < n; i++) {
            cin >> temp;
            sum += temp;
        }
        cout << int(ceil(sum / double(n))) << endl;
    }

    return 0;
}