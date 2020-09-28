#include <bits/stdc++.h>
using namespace std;

// 0 based indexed
class SegmentTree {
    private:
        int treeSize, arrSize;
        vector<pair<int, int>> tree;

        int __query(int qLow, int qHigh, int low, int high, int pos) {
            if (qLow <= low and qHigh >= high) {
                return tree[pos].first + (high - low + 1) * tree[pos].second;
            }
            if ((qLow > high) or (qHigh < low)) {
                return 0;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            if (tree[pos].second) {
                int add = tree[pos].second;
                tree[pos].first += (high - low + 1) * add;
                tree[left].second += add;
                tree[right].second += add;
                tree[pos].second = 0;
            }
            int leftVal = __query(qLow, qHigh, low, mid, left);
            int rightVal = __query(qLow, qHigh, mid + 1, high, right);
            return leftVal + rightVal;
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                tree[pos].second += val;
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            if (tree[pos].second) {
                int add = tree[pos].second;
                tree[left].second += add;
                tree[right].second += add;
                tree[pos].second = 0;
            }
            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            tree[pos].first = tree[left].first + tree[right].first 
            + (mid - low + 1) * tree[left].second + (high - mid) * tree[right].second;
        }

        void __build(vector<int> &arr, int pos, int low, int high) {
            if (low == high) {
                tree[pos].first = arr[low];
            } else {
                int mid = (low + high) / 2;
                int left = pos * 2 + 1;
                int right = pos * 2 + 2;

                __build(arr, left, low, mid);
                __build(arr, right, mid + 1, high);
                tree[pos].first = tree[left].first + tree[right].first;
            }
        }

    public:
        SegmentTree(int n) {
            arrSize = n;
            treeSize = 4 * arrSize;
            tree.resize(treeSize, { 0, 0 });
        }

        SegmentTree(vector<int> &arr) {
            arrSize = arr.size();
            treeSize = 4 * arrSize;
            tree.resize(treeSize, { 0, 0 });
            __build(arr, 0, 0, arrSize - 1);
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