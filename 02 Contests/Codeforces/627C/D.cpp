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

#include <bits/stdc++.h> 
using namespace std; 
  
// Structure which will store both 
// array elements and queries. 
struct node { 
    int pos; 
    int l; 
    int r; 
    int val; 
}; 
  
// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
    // If 2 values are equal the query will 
    // occur first then array element 
    if (a.val == b.val) 
        return a.l > b.l; 
  
    // Otherwise sorted in descending order. 
    return a.val > b.val; 
} 
  
// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx) 
{ 
    while (idx <= n) { 
        BIT[idx]++; 
        idx += idx & (-idx); 
    } 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
    int ans = 0; 
    while (idx) { 
        ans += BIT[idx]; 
  
        idx -= idx & (-idx); 
    } 
    return ans; 
} 
  
// Function to solve the queries offline 
void solveQuery(int arr[], int n, int QueryL[], 
                int QueryR[], int QueryK[], int q) 
{ 
    // create node to store the elements 
    // and the queries 
    node a[n + q + 1]; 
    // 1-based indexing. 
  
    // traverse for all array numbers 
    for (int i = 1; i <= n; ++i) { 
        a[i].val = arr[i - 1]; 
        a[i].pos = 0; 
        a[i].l = 0; 
        a[i].r = i; 
    } 
  
    // iterate for all queries 
    for (int i = n + 1; i <= n + q; ++i) { 
        a[i].pos = i - n; 
        a[i].val = QueryK[i - n - 1]; 
        a[i].l = QueryL[i - n - 1]; 
        a[i].r = QueryR[i - n - 1]; 
    } 
  
    // In-built sort function used to 
    // sort node array using comp function. 
    sort(a + 1, a + n + q + 1, comp); 
  
    // Binary Indexed tree with 
    // initially 0 at all places. 
    int BIT[n + 1]; 
  
    // initially 0 
    memset(BIT, 0, sizeof(BIT)); 
  
    // For storing answers for each query( 1-based indexing ). 
    int ans[q + 1]; 
  
    // traverse for numbers and query 
    for (int i = 1; i <= n + q; ++i) { 
        if (a[i].pos != 0) { 
  
            // call function to returns answer for each query 
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 
  
            // This will ensure that answer of each query 
            // are stored in order it was initially asked. 
            ans[a[i].pos] = cnt; 
        } 
        else { 
            // a[i].r contains the position of the 
            // element in the original array. 
            update(BIT, n, a[i].r); 
        } 
    } 
    // Output the answer array 
    int res = 0;
    for (int i = 1; i <= q; ++i) { 
        res += ans[i];
    } 
    cout << res << endl;
} 

int32_t main() { fastio;
    time_t start = now();

    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] -= x;
        // cout << arr[i] << " ";
    }
    int QueryL[n - 1];
    int QueryR[n - 1];
    for (int i = 0; i < n - 1; i++) {
        QueryL[i] = i + 2;
        // cout << QueryL[i] << " ";
    }
    for (int i = 0; i < n - 1; i++) {
        QueryR[i] = n;
        // cout << QueryR[i] << " ";
    }
    int QueryK[n - 1];
    for (int i = 0; i < n - 1; i++) {
        QueryK[i] = 0 - arr[i];
    }
    solveQuery(arr, n, QueryL, QueryR, QueryK, n - 1);

    cerr << "TIME => " << now() - start << endl;
    return 0;
}