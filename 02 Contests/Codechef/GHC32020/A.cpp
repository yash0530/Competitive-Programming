#include <bits/stdc++.h>
using namespace std;
#define deb(x) cerr << #x << " => " << x << "\n"

#define endl "\n"
#define int long long int
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int findXOR(int n) 
{ 
    int mod = n % 4; 
  
    // If n is a multiple of 4 
    if (mod == 0) 
        return n; 
  
    // If n % 4 gives remainder 1 
    else if (mod == 1) 
        return 1; 
  
    // If n % 4 gives remainder 2 
    else if (mod == 2) 
        return n + 1; 
  
    // If n % 4 gives remainder 3 
    else if (mod == 3) 
        return 0; 
} 
  
// Function to return the XOR of elements 
// from the range [l, r] 
int findXOR(int l, int r) 
{ 
    return (findXOR(l - 1) ^ findXOR(r)); 
} 

int32_t  main() { fastio;
    time_t start = now();

    int n, q;
    cin >> n >> q;

    set<int> zeros, ones;
    int queries[q][2];
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        zeros.insert(queries[i][1]);
        zeros.insert(queries[i][1] + 1);
        if (queries[i][1] != 1)
            zeros.insert(queries[i][1] - 1);
    }

    for (auto q : queries) {
        if (q[0] == 1) {
            zeros.erase(q[1]);
            ones.insert(q[1]);
        } else {
            int left = *zeros.lower_bound(q[1]);
            int right = n;
            auto m = ones.upper_bound(left);
            if (m != ones.end())
                right = *m - 1;
            cout << findXOR(left, right) << endl;
        }
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}