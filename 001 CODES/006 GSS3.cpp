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

struct node {
    int sum;
    int pSum;
    int sSum;
    int maxSum;
};

class SegmentTree {
    private:
        node *tree;
        int *arr;
        int treeSize;
        int arrSize;
 
        void __buildTree(int low, int high, int pos) {
            if (low == high) {
                tree[pos] = { arr[low], arr[low], arr[low], arr[low] };
            } else {
                int mid = (low + high) / 2, left = 2 * pos + 1, right = 2 * pos + 2;
 
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
 
            if (qLow <= low and qHigh >= high)
                return tree[pos];
 
            else if (qLow > high or qHigh < low)
                return result;
 
            else {
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

        void __update(int loc, int value, int low, int high, int pos) {
            if (loc == low and loc == high) {
                tree[pos].maxSum = value;
                tree[pos].pSum = value;
                tree[pos].sSum = value;
                tree[pos].sum = value;
            }
 
            else if (loc > high or loc < low)
                return;
 
            else {
                int mid = (low + high) / 2, left = 2 * pos + 1, right = 2 * pos + 2;
 
                __update(loc, value, low, mid, left);
                __update(loc, value, mid + 1, high, right);
 
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
 
    public:
        SegmentTree(int array[], int n) {
            arr = array;
            arrSize = n;
            treeSize = 2 * (1 << (int) ceil(log2(n))) - 1;
 
            tree = (node *) malloc(sizeof(node) * treeSize);
            __buildTree(0, arrSize - 1, 0);
        }
 
        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0).maxSum;
        }

        void _update(int loc, int value) {
            __update(loc, value, 0, arrSize - 1, 0);
        }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n; int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    SegmentTree st(arr, n);
 
    int m; cin >> m;
    while (m--) {
        int s, x, y;
        cin >> s >> x >> y;
        if (s) cout << st._query(--x, --y) << endl;
        else st._update(--x, y);
    }
}