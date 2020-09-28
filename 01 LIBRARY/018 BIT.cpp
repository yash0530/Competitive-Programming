#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
const int maxN = 1e5 + 5;
int tree[maxN];

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
}