#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pout cout << fixed << setprecision(10)
#define MOD (int) (1e9 + 7)

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool isPossible(string s, int n) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        a += s[i] == '(';
        b += s[i] == ')';
    }
    return a == b;
}

int getCount(string s, int n) {
    int count = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') count++;
        else count--;
        arr[i] = count;
    }
    count = *min_element(arr.begin(), arr.end());
    int res = 0;
    for (auto a : arr) {
        res += count == a;
    }
    return res;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    string s; cin >> s;
    if (isPossible(s, n)) {
        int count = 0, l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(s[i], s[j]);
                int x = getCount(s, n);
                if (x > count) {
                    count = x;
                    l = i;
                    r = j;
                }
                swap(s[i], s[j]);
            }
        }
        cout << count << endl << l + 1 << " " << r + 1 << endl;
    } else {
        cout << 0 << endl << 1 << " " << 1 << endl;
    }
    return 0;
}