#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
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

struct node {
    int sum;
    int pSum;
    int sSum;
    int maxSum;
};

class SegmentTree {
    private:
        node *tree;
        vector<int> arr;
        int treeSize;
        int arrSize;

        void __buildTree(int low, int high, int pos) {
            if (low == high) {
                tree[pos] = { arr[low], arr[low], arr[low], arr[low] };
            } else {

                int mid = (high + low) / 2;
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;
 
                __buildTree(low, mid, left);
                __buildTree(mid + 1, high, right);
 
                tree[pos].sum = tree[left].sum + tree[right].sum;
                tree[pos].pSum = max(tree[left].pSum, tree[left].sum + tree[right].pSum);
                tree[pos].sSum = max(tree[right].sSum, tree[right].sum + tree[left].sSum);
                tree[pos].maxSum =
                max(tree[pos].sSum,
                    max(tree[pos].pSum,
                        max(tree[left].maxSum,
                            max(tree[right].maxSum,
                                tree[left].sSum + tree[right].pSum
                            )
                        )
                    )
                );
            }
        }
 
        node __query(int qLow, int qHigh, int low, int high, int pos) {
            node result = { INT_MIN, INT_MIN, INT_MIN, INT_MIN };

            // total overlap
            if (qLow <= low and qHigh >= high) {
                return tree[pos];
            }
 
            // no overlap
            else if (qLow > high or qHigh < low) {
                return result;
            }
 
            // partial overlap
            else
            {
                int mid = (high + low) / 2;
 
                if (qLow > mid)
                    return __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
                if (qHigh <= mid)
                    return __query(qLow, qHigh, low, mid, 2 * pos + 1);
 
                node left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                node right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
 
                result.sum = left.sum + right.sum;
                result.pSum = max(left.pSum, left.sum + right.pSum);
                result.sSum = max(right.sSum, right.sum + left.sSum);
                result.maxSum = 
                max(result.pSum,
                    max(result.sSum,
                        max(left.maxSum,
                            max(right.maxSum,
                                left.sSum + right.pSum
                            )
                        )
                    )
                );
 
                return result;
            }
        }
 
    public:
        SegmentTree(vector<int> array, int n) {
            arr = array;
            arrSize = n;
            treeSize = 2 * (1 << (int) ceil(log2(n))) - 1;
 
            tree = (node *) malloc(sizeof(node) * treeSize);
            __buildTree(0, arrSize - 1, 0);
        }
 
        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0).maxSum;
        }
};

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(2 * n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i + n] = arr[i];
        }
        SegmentTree st(arr, 2 * n);
        for (int i = 0; i < n; i++) {
            cout << st._query(i, i + n - 1) << " ";
        } cout << endl;
    }
    return 0;
}