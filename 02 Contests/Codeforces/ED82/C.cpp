#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<char> res(200, '0');
        int index = 100;
        res[index] = s[0];
        vector<int> freq(128); bool poss = true;
        freq[s[0]]++;
        for (int i = 1; i < s.length(); i++) {
            if (freq[s[i]]) {
                if (res[index + 1] != s[i] and res[index - 1] != s[i]) {
                    poss = false;
                    break;
                } else if (res[index + 1] == s[i]) {
                    index++;
                } else {
                    index--;
                }
            } else {
                if (res[index + 1] != '0' and res[index - 1] != '0') {
                    poss = false;
                    break;
                } else if (res[index + 1] == '0') {
                    freq[s[i]]++;
                    index++;
                    res[index] = s[i];
                } else {
                    freq[s[i]]++;
                    index--;
                    res[index] = s[i];
                }
            }
        }
        if (!poss) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            vector<int> done(26);
            for (int i = 0; i < res.size(); i++) {
                if (res[i] != '0') {
                    cout << res[i];
                    done[res[i] - 'a']++;
                }
            }
            for (int i = 0; i < done.size(); i++) {
                if (!done[i]) {
                    cout << (char)('a' + i);
                }
            }
            cout << endl;
        }
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}