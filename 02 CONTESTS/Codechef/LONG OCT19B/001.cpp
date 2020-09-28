#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 1;
        for (int i = 1; i < n; i++) {
            int possible = true;
            for (int j = i - 1; j >= 0 and j >= i - 5; j--) {
                if (arr[j] <= arr[i]) {
                    possible = false;
                    break;
                }
            }
            count += possible;
        }
        cout << count << endl;
    }
	return 0;
}
