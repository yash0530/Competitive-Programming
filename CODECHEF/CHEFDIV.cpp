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

int32_t main() {
    fastio;
    int a, b;
    cin >> a >> b;

    int limit = floor(sqrt(b)) + 1;
    vector<int> primes;
    vector<bool> marked1(limit + 1);
    for (int i = 2; i <= limit; i++) { 
        if (marked1[i] == false) {
            primes.push_back(i); 
            for (int j = i; j <= limit; j += i) {
                marked1[j] = true;
            }
        }
    }

    int n = b - a + 1;
    vector<pair<priority_queue<int>, int>> divisors(n, { priority_queue<int>(), 1 });
    vector<bool> marked(n + 1);
    vector<int> vals(n + 1);
    for (int i = 0; i <= n; i++) {
        vals[i] = a + i;
    }

    for (int i = 0; i < (int) primes.size(); i++) {
        int loLim = floor(a / primes[i]) * primes[i];
        if (loLim < a) 
            loLim += primes[i]; 
        if(loLim == primes[i]) 
            loLim += primes[i];

        for (int j = loLim; j <= b; j += primes[i]) {
            marked[j - a] = true;
            int count = 0;
            int num = vals[j - a];
            while (num % primes[i] == 0) {
                num /= primes[i];
                count++;
            }
            vals[j - a] = num;
            divisors[j - a].first.push(count);
            divisors[j - a].second *= (count + 1);
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (vals[i] > 1) {
            divisors[i].first.push(1);
            divisors[i].second *= 2;
        }
    }

    int sum = 0;
    for (int i = a; i <= b; i++) {
        auto pq = divisors[i - a].first;
        int total = divisors[i - a].second;
        int top, pdt = total;
        while (!pq.empty()) {
            top = pq.top(); pq.pop();
            pdt = (pdt * top / (top + 1));
            top--;
            total += pdt;
            if (top) {
                pq.push(top);
            }
        }
        sum += (total - 1);
    }
    cout << sum << endl;
    return 0;
}