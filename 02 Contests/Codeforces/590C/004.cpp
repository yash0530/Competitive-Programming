#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class SegmentTree {
    private:
        int *tree;
        string arr;
        int treeSize;
        int arrSize;

        void __buildTree(int low, int high, int pos) {
            if (low == high) {
                tree[pos] = 1 << (arr[low] - 'a');
            } else {
                int mid = (low + high) / 2, left = 2 * pos + 1, right = 2 * pos + 2;
                if (left == -1) return;
                __buildTree(low, mid, left);
                __buildTree(mid + 1, high, right);
 
                tree[pos] = tree[left] | tree[right];
            }
        }
 
        int __query(int qLow, int qHigh, int low, int high, int pos) {
 
            if (qLow <= low and qHigh >= high)
                return tree[pos];
 
            else if (qLow > high or qHigh < low)
                return 0;
 
            else {
                int mid = (high + low) / 2;
 
                if (qLow > mid)
                    return __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
                if (qHigh <= mid)
                    return __query(qLow, qHigh, low, mid, 2 * pos + 1);
 
                int left = __query(qLow, qHigh, low, mid, 2 * pos + 1);
                int right = __query(qLow, qHigh, mid + 1, high, 2 * pos + 2);
 
                return left | right;
            }
        }

        void __update(int loc, char value, int low, int high, int pos) {
            if (loc == low and loc == high) {
                tree[pos] = 1 << (value - 'a');
            }
 
            else if (loc > high or loc < low)
                return;
 
            else {
                int mid = (low + high) / 2, left = 2 * pos + 1, right = 2 * pos + 2;
 
                __update(loc, value, low, mid, left);
                __update(loc, value, mid + 1, high, right);
 
                tree[pos] = tree[left] | tree[right];
            }
        }
 
    public:
        SegmentTree(string array, int n) {
            arr = array;
            arrSize = n;
            treeSize = 2 * (1 << int(ceil(log2(n)))) - 1;
 
            tree = new int[treeSize];
            __buildTree(0, arrSize - 1, 0);
        }
 
        int _query(int qLow, int qHigh) {
            return __builtin_popcount(__query(qLow, qHigh, 0, arrSize - 1, 0));
        }

        void _update(int loc, int value) {
            __update(loc, value, 0, arrSize - 1, 0);
        }
};

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int q; cin >> q;

    SegmentTree seg(s, s.length());
    while (q--) {
        int s; cin >> s;
        if (s == 1) {
            int loc; char val;
            cin >> loc >> val;
            seg._update(--loc, val);
        } else {
            int low, high;
            cin >> low >> high;
            cout << seg._query(--low, --high) << endl;
        }
    }

    return 0;
}