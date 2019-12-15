#include <bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << endl
using namespace std;

int32_t main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res(n);
    int last_inserted = -1, elems = ((int) 1, (k - 1) * 0.25);
    for (int i = n - 1, j = n; i >= 0; i--, j--) {
        res[i] = j;
        if (arr[i] != j) {
            last_inserted = j;
            elems--;
        }
        if (elems == 0) break;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (arr[i] < last_inserted) {
            res[j++] = arr[i];
        } 
    }

    for (auto r : res) {
        cout << r << " ";
    } cout << endl;

    return 0;
}