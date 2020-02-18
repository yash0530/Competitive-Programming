#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

vector<vector<int>> lookup(1e5 + 5);

int32_t main() { fastio;
    int t; cin >> t;
    for (int i = 1; i <= 1e5; i++) {
        int x = i;
        vector<int> divisors;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x % i == 0) {
                divisors.push_back(i);          
                if (i * i != x) {
                    divisors.push_back(x / i);
                }
            }
        }
        set<int> final_d;
        for (int i = 0; i < divisors.size(); i++) {
            for (int j = i; j < divisors.size(); j++) {
                if (((x * x) % (divisors[i] * divisors[j]) == 0) and !final_d.count(divisors[i] * divisors[j])) {
                    final_d.insert(divisors[i] * divisors[j]);
                }
            }
        }
        lookup[i] = (vector<int>(final_d.begin(), final_d.end())); 
    }
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        vector<int> x_present(2 * 1e5 + 5), y_present(2 * 1e5 + 5);
        vector<int> x_vector(n), y_vector(m);
        bool x_zero = false;
        for (int i = 0; i < n; i++) {
            cin >> x_vector[i];
            x_zero |= (x_vector[i] == 0);
            x_present[x_vector[i] + 1e5 + 2]++;
        }
        bool y_zero = 0;
        for (int i = 0; i < m; i++) {
            cin >> y_vector[i];
            y_zero |= (y_vector[i] == 0);
            y_present[y_vector[i] + 1e5 + 2]++;
        }
        int count = (x_zero or y_zero) * (n - x_zero) * (m - y_zero);
        for (auto x : x_vector) {
            vector<int> divisors = lookup[abs(x)];
            int low = 0, high = divisors.size() - 1;
            while (low <= high) {
                if (low != high and divisors[low] <= 1e5 and divisors[high] <= 1e5) {
                    count += y_present[divisors[low] + 1e5 + 2] and y_present[-1 * divisors[high] + 1e5 + 2];
                    count += y_present[-1 * divisors[low] + 1e5 + 2] and y_present[divisors[high] + 1e5 + 2];
                } else if (divisors[low] <= 1e5 and divisors[high] <= 1e5) {
                    count += y_present[divisors[low] + 1e5 + 2] and y_present[-1 * divisors[high] + 1e5 + 2];
                }
                low++; high--;
            }
        }
        for (auto x : y_vector) {
            vector<int> divisors = lookup[abs(x)];
            int low = 0, high = divisors.size() - 1;
            while (low <= high) {
                if (low != high and divisors[low] <= 1e5 and divisors[high] <= 1e5) {
                    count += x_present[divisors[low] + 1e5 + 2] and x_present[-1 * divisors[high] + 1e5 + 2];
                    count += x_present[-1 * divisors[low] + 1e5 + 2] and x_present[divisors[high] + 1e5 + 2];
                } else if (divisors[low] <= 1e5 and divisors[high] <= 1e5) {
                    count += x_present[divisors[low] + 1e5 + 2] and x_present[-1 * divisors[high] + 1e5 + 2];
                }
                low++; high--;
            }
        }
        cout << count << endl;
    }
    return 0;
}