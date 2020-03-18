#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> tree;

void update(int index, int val) {
    while (index <= n) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

int32_t main() {
    int n; cin >> n;
    tree.resize(n + 1);
}