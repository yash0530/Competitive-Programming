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
    int value;
    int additional;
};

class SegmentTree {
    private:
        node *tree;
        int treeSize;
        int arrSize;

        int __query(int qLow, int qHigh, int low, int high, int pos) {
            // total overlap
            if (qLow <= low and qHigh >= high) {
                return tree[pos].value + (high - low + 1) * tree[pos].additional;
            }

            // no overlap
            else if (qLow > high or qHigh < low) {
                return 0;
            }

            // partial overlap
            else {
                int mid = (high + low) / 2;

                // taking care of additionals
                if (tree[pos].additional != 0) {
                    int add = tree[pos].additional;
                    tree[pos].value += (high - low + 1) * add;
                    tree[pos].additional = 0;
 
                    tree[2 * pos + 1].additional += add;
                    tree[2 * pos + 2].additional += add;
                }

                int left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                int right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
                return left + right;
            }
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            // total overlap
            if (qLow <= low and qHigh >= high) {
                tree[pos].additional += val;
            }

            // no overlap
            else if (qLow > high or qHigh < low) {
                return;
            }

            // partial overlap
            else {
                int mid = (high + low) / 2;

                // taking care of additionals
                if (tree[pos].additional != 0) {
                    int add = tree[pos].additional;
                    tree[pos].additional = 0;

                    tree[2 * pos + 1].additional += add;
                    tree[2 * pos + 2].additional += add;
                }

                __update(qLow, qHigh, low, mid, 2 * pos + 1, val);
                __update(qLow, qHigh, mid + 1, high, 2 * pos + 2, val);
                tree[pos].value = tree[2 * pos + 1].value + tree[2 * pos + 2].value
                                    + (mid - low + 1) * tree[2 * pos + 1].additional 
                                    + (high - mid) * tree[2 * pos + 2].additional;
            }
        }

    public:
        SegmentTree(int n) {
            arrSize = n;
            treeSize = 2 * (1 << (int) ceil(log2(n))) - 1;

            tree = new node[treeSize];
            for (int i = 0; i < treeSize; i++) {
                tree[i].value = 0;
                tree[i].additional = 0;
            }
        }

        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0);
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        cin.ignore();
        int n; int updates;
        cin >> n >> updates;
 
        SegmentTree st(n);
        while (updates--) {
            int status; cin >> status;
            if (status) {
                int a, b;
                cin >> a >> b;
                cout << st._query(--a, --b) << endl;
            }
            else {
                int a, b, val;
                cin >> a >> b >> val;
                st._update(--a, --b, val);
            }
        }
    }
}

// building an seg tree from a given array
// for sum
void build(int tree[], int arr[], int pos, int low, int high) {
    if (low == high) {
        tree[pos] = arr[low];
    } else {
        int mid = (low + high) / 2;
        build(tree, arr, pos * 2 + 1, low, mid);
        build(tree, arr, pos * 2 + 2, mid + 1, high);
        tree[pos] = tree[pos * 2 + 1] + tree[pos * 2 + 2];
    }
}