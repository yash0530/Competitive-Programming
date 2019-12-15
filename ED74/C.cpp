#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define deb(x) cout << #x << " => " << x << endl
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; cin >> q;
    while (q--) {
        int h, n; cin >> h >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int i = 1, height = h, count = 0;
        while (i < n and height > 2) {
            if (height - arr[i] == 1) {
                if (i == n - 1) {
                    count++;
                    break;
                } 
                if (height - arr[i + 1] == 2) {
                    height = arr[i + 1];
                    i += 2;
                } else {
                    count++;
                    height -= 2;
                    i++;
                }
            } else {
                height = arr[i] + 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}