#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int x2[n];
        for (int i = 0; i < n; i++) {
            x2[i] = arr[i];
        }

        ll c = k / n;
        ll m = k % n;

        if (c % 3 == 1) {
            for (int i = 0; i < n; i++) {
                arr[i % n] = arr[i % n] ^ arr[n - (i % n) - 1];
            }
        } else if (c % 3 == 2) {
            for (int i = 0; i < n; i++) {
                arr[i % n] = arr[i % n] ^ arr[n - (i % n) - 1];
            }
            for (int i = 0; i < n; i++) {
                arr[i % n] = arr[i % n] ^ arr[n - (i % n) - 1];
            }
        }

        if (k > n / 2 and n & 1) {
            arr[n / 2] = 0;
        }

        for (int i = 0; i < m; i++) {
            arr[i % n] = arr[i % n] ^ arr[n - (i % n) - 1];
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }

    return 0;
}