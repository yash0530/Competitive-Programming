#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18

const int maxN = 1e5 + 5;
int n;
int tree[4 * maxN], lazy[4 * maxN], arr[maxN];

// ----------------- STANDARD SEG TREE NO LAZY --------------------------- //

// building tree from range sum
void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

// sum over range
int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v*2, tl, tm) + sum(max(l, tm+1), r, v*2+1, tm+1, tr);
}

// update a loc
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

// ------------------- Max subarray sum in range ---------------- //
struct data {
    int sum, pref, suff, ans;
};

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL, val);
    return res;
}

// -------------------- Range update add, Range query Max (LAZY) ---------- //
void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        updateRange(l, min(r, tm), addend, v*2, tl, tm);
        updateRange(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int queryMax(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(queryMax(l, min(r, tm), v*2, tl, tm), queryMax(max(l, tm+1), r, v*2+1, tm+1, tr));
}

// --------------------- Range Update Add, Range Query sum (LAZY) ---------------------- //
// 0 based indexed
// Implementation by ScaryTerry
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

            if (tree[pos].second != 0) {
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

            if (tree[pos].second != 0) {
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

// ------------------------------ MAXX ------------------------- //
namespace maxx {

    int *arr, *tree, *lazy;
    int n;

    void build(int nn) {
        n = nn + 1;
        arr = new int[n];
        tree = new int[4 * n];
        lazy = new int[4 * n];
        for (int i = 0; i < n; i++) arr[i] = 0;
        for (int i = 0; i < 4 * n; i++) tree[i] = 0;
        for (int i = 0; i < 4 * n; i++) lazy[i] = 0;
    }

    void push(int v) {
        tree[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        tree[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            tree[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            updateRange(l, min(r, tm), addend, v*2, tl, tm);
            updateRange(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

    int queryMax(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
        if (l > r)
            return -1000000;
        if (l == tl && tr == r) 
            return tree[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(queryMax(l, min(r, tm), v*2, tl, tm), queryMax(max(l, tm+1), r, v*2+1, tm+1, tr));
    }
};

// ------------------------------ MINN ------------------------- //
namespace minn {

    int *arr, *tree, *lazy;
    int n;

    void build(int nn) {
        n = nn + 1;
        arr = new int[n];
        tree = new int[4 * n];
        lazy = new int[4 * n];
        for (int i = 0; i < n; i++) arr[i] = 0;
        for (int i = 0; i < 4 * n; i++) tree[i] = 0;
        for (int i = 0; i < 4 * n; i++) lazy[i] = 0;
    }

    void push(int v) {
        tree[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        tree[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            tree[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            updateRange(l, min(r, tm), addend, v*2, tl, tm);
            updateRange(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
            tree[v] = min(tree[v*2], tree[v*2+1]);
        }
    }

    int queryMin(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
        if (l > r) 
            return 1000000;
        if (l == tl && tr == r) 
            return tree[v];
        push(v);
        int tm = (tl + tr) / 2;
        return min(queryMin(l, min(r, tm), v*2, tl, tm), queryMin(max(l, tm+1), r, v*2+1, tm+1, tr));
    }
};

// ----------------- SEG TREE TOURIST ----------------------------- //
class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int sum = 0;
    bool put = false;
    int val = 0;
 
    void apply(int l, int r, int v) {
      put = true;
      val = v;
      sum = v * (r - l + 1);
    }
  };
 
  node unite(const node &a, const node &b) const {
    node res;
    res.sum = a.sum + b.sum;
    return res;
  }
 
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].put) {
      tree[x + 1].apply(l, y, tree[x].val);
      tree[z].apply(y + 1, r, tree[x].val);
      tree[x].put = false;
    }
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
 
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
 
  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
 
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
 
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
 
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
 
  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once
 
  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
 
  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};