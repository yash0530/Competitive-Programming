#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl

int H[1000001];
int stars[1000001];

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        memset(H, 0, sizeof H);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            H[arr[i]]++;
        }

        ll max_star = 0;
        memset(stars, 0, sizeof stars);
        for (int i = 0; i < n; i++) {
            H[arr[i]]--;
            for (int j = 1; j * j <= arr[i]; j++) {
                if (arr[i] % j == 0) {
                    if (H[j] > 0) {
                        stars[j]++;
                        max_star = max(max_star, (ll) stars[j]);
                    }
                    if (j * j != arr[i]) {
                        if (H[arr[i] / j] > 0) {
                            stars[arr[i] / j]++;
                            max_star = max(max_star, (ll) stars[arr[i] / j]);
                        }
                    }
                }
            }
        }
        cout << max_star << endl;
    }

    return 0;
}