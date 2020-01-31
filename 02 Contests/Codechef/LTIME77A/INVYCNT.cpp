#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define int long long
#define uint unsigned long long
#define MOD (int) (1e9 + 7)
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    } return res;
}

int merge(vector<int> &a, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;
    int count = 0;
    while (i <= mid and j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
            count += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(a[j]);
        j++;
    }
    for (int i = 0, j = low; j <= high; j++, i++) {
        a[j] = temp[i];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }
    return count;
}

int32_t main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = mergeSort(arr, 0, arr.size() - 1);
        vector<int> b = arr;
        for (auto a : arr) {
            b.push_back(a);
        }
        int mergeCount = merge(b, 0, n - 1, 2 * n - 1);
        int res = k * count + k * (k - 1) * mergeCount / 2;
        cout << res << endl;
    }
    return 0;
}