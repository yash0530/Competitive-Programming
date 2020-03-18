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

int n, k;
const int maxN = 505;
int adj[maxN][maxN], arr[maxN];

bool bpm(int bpGraph[maxN][maxN], int u, bool seen[], int matchR[]) { 
    for (int v = 0; v < n; v++) { 
        if (bpGraph[u][v] && !seen[v]) { 
            seen[v] = true;  
            if (matchR[v] < 0 or bpm(bpGraph, matchR[v], seen, matchR)) { 
                matchR[v] = u;
                return true;
            }
        }
    }
    return false; 
}
 
int maxBPM(int bpGraph[maxN][maxN]) { 
    int matchR[n];
    memset(matchR, -1, sizeof(matchR)); 
    int result = 0;  
    for (int u = 0; u < n; u++) {
        bool seen[n];
        memset(seen, 0, sizeof(seen)); 
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
	// printing ans
	cout << n - result << endl;
	for (int i = 0; i < n; i++) {
		cout << matchR[i] + 1 << " ";
	} cout << endl;
    return result;
}

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(adj, 1, sizeof (adj));
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        while (k--) {
            for (int i = 0; i < n; i++) {
                cin >> arr[i]; arr[i]--;
                for (int j = 0; j < i; j++) {
					// ulta
                    adj[arr[j]][arr[i]] = 0;
                }
            }
        }
		maxBPM(adj);
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}