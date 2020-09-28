#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int maxN = 1e5 + 5;

struct suffixNode {
    int sum;
    int sSum;
};

int n, q;
int arr[maxN];

suffixNode suffixTree[4 * maxN];
class SegmentTreeSuffix {
    private:
        int treeSize;
        int arrSize;

        void __buildTree(int low, int high, int pos) {
            if (low == high) {
                suffixTree[pos] = { arr[low], arr[low] };
            } else {

                int mid = (high + low) / 2;
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;
 
                __buildTree(low, mid, left);
                __buildTree(mid + 1, high, right);
 
                suffixTree[pos].sum = suffixTree[left].sum + suffixTree[right].sum;
                suffixTree[pos].sSum = max(suffixTree[right].sSum, suffixTree[right].sum + suffixTree[left].sSum);
            }
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                suffixTree[pos] = { val, val };
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            suffixTree[pos].sum = suffixTree[left].sum + suffixTree[right].sum;
            suffixTree[pos].sSum = max(suffixTree[right].sSum, suffixTree[right].sum + suffixTree[left].sSum);
        }
 
        suffixNode __query(int qLow, int qHigh, int low, int high, int pos) {
            suffixNode result = { INT_MIN, INT_MIN };

            // total overlap
            if (qLow <= low and qHigh >= high) {
                return suffixTree[pos];
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
 
                suffixNode left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                suffixNode right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
 
                result.sum = left.sum + right.sum;
                result.sSum = max(right.sSum, right.sum + left.sSum);
                return result;
            }
        }
 
    public:
        SegmentTreeSuffix() {
            arrSize = n;
            treeSize = 2 * n;
            __buildTree(0, arrSize - 1, 0);
        }
 
        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0).sSum;
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

// ----------------------------------------------------------- //

struct prefixNode {
    int sum;
    int pSum;
};

prefixNode prefTree[4 * maxN];
class SegmentTreePrefix {
    private:
        int treeSize;
        int arrSize;

        void __buildTree(int low, int high, int pos) {
            if (low == high) {
                prefTree[pos] = { arr[low], arr[low] };
            } else {

                int mid = (high + low) / 2;
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;
 
                __buildTree(low, mid, left);
                __buildTree(mid + 1, high, right);
 
                prefTree[pos].sum = prefTree[left].sum + prefTree[right].sum;
                prefTree[pos].pSum = max(prefTree[left].pSum, prefTree[left].sum + prefTree[right].pSum);
            }
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                prefTree[pos] = { val, val };
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            prefTree[pos].sum = prefTree[left].sum + prefTree[right].sum;
            prefTree[pos].pSum = max(prefTree[left].pSum, prefTree[left].sum + prefTree[right].pSum);
        }
 
        prefixNode __query(int qLow, int qHigh, int low, int high, int pos) {
            prefixNode result = { INT_MIN, INT_MIN };

            // total overlap
            if (qLow <= low and qHigh >= high) {
                return prefTree[pos];
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
 
                prefixNode left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                prefixNode right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
 
                result.sum = left.sum + right.sum;
                result.pSum = max(left.pSum, left.sum + right.pSum);
                return result;
            }
        }
 
    public:
        SegmentTreePrefix() {
            arrSize = n;
            treeSize = 4 * n;
            __buildTree(0, arrSize - 1, 0);
        }
 
        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0).pSum;
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

int tree[4 * maxN];
class SegmentTreeSum {
    private:
        int treeSize, arrSize;

        int __query(int qLow, int qHigh, int low, int high, int pos) {
            if (qLow <= low and qHigh >= high) {
                return tree[pos];
            }
            if ((qLow > high) or (qHigh < low)) {
                return 0;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            int leftVal = __query(qLow, qHigh, low, mid, left);
            int rightVal = __query(qLow, qHigh, mid + 1, high, right);
            return leftVal + rightVal;
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                tree[pos] = val;
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            tree[pos] = tree[left] + tree[right];
        }

        void __build(int pos, int low, int high) {
            if (low == high) {
                tree[pos] = arr[low];
            } else {
                int mid = (low + high) / 2;
                int left = pos * 2 + 1;
                int right = pos * 2 + 2;

                __build(left, low, mid);
                __build(right, mid + 1, high);
                tree[pos] = tree[left] + tree[right];
            }
        }

    public:
        SegmentTreeSum() {
            arrSize = n;
            treeSize = 4 * arrSize;
            // tree.resize(treeSize, 0);
            __build(0, 0, arrSize - 1);
        }

        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0);
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

int32_t main() { fastio;

    int t; cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        SegmentTreeSum sts;
        SegmentTreePrefix stpref;
        SegmentTreeSuffix stsuff;

        char stat; int x, y;
        while (q--) {
            cin >> stat >> x >> y;
            x--; y--;
            if (stat == 'Q') {
                int res = sts._query(x, y);
                if (x != 0)
                    res = max(res, res + stsuff._query(0, x - 1));
                if (y != n - 1)
                    res = max(res, res + stpref._query(y + 1, n - 1));
                cout << res << endl;
            } else {
                y++;
                sts._update(x, x, y);
                stsuff._update(x, x, y);
                stpref._update(x, x, y);
            }
        }
    }

    return 0;
}