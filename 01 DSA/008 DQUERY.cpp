#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m) vector<vector<int>> x(n, vector<int> (m))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MAX 1000001

int n, sqn;

bool comp(vector<int> a, vector<int> b) {
    if ((a[1] / sqn) == (b[1] / sqn)) {
        return a[2] < b[2];
    }
    return (a[1] / sqn) < (b[1] / sqn);
}

int32_t main() {
    fastio;
    cin >> n;
    sqn = floor(sqrt(n));
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q; cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        queries[i] = { i, a, b };
    }
    sort(queries.begin(), queries.end(), comp);

    int count = 1;
    vector<int> freq(MAX);
    vector<int> res(q);
    int start = 0, end = 0;
    freq[arr[start]]++;
    for (auto x : queries) {
        int l = x[1], r = x[2];
        if (end > r) {
            while (end != r) {
                freq[arr[end]]--;
                count -= freq[arr[end]] == 0;
                end--;
            }
        }
        if (end < r) {
            while (end != r) {
                end++;
                freq[arr[end]]++;
                count += freq[arr[end]] == 1;
            }
        }
        if (start > l) {
            while (start != l) {
                start--;
                freq[arr[start]]++;
                count += freq[arr[start]] == 1;
            }
        }
        if (start < l) {
            while (start != l) {
                freq[arr[start]]--;
                count -= freq[arr[start]] == 0;
                start++;
            }
        }
        res[x[0]] = count;
    }
    
    for (auto r : res) {
        cout << r << endl;
    }
    return 0;
}