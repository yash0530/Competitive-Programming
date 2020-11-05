#include <bits/stdc++.h>
using namespace std;

int getDefiniteFinds(vector<int> &arr) {
    int n = arr.size();

    // suffix_min denotes min (i...n)
    vector<int> suff_min(n + 1);
    suff_min[n] = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        suff_min[i] = min(suff_min[i + 1], arr[i]);
    }

    // mn denotes max(0...i-1)
    int mn = INT_MIN, ans = 0;
    for (int i = 0; i < n; i++) {
        // if max element till i-1 is less than element at i
        // if min element from i+1 to n is greater than element at i
        // the element will surely be found
        if (mn < arr[i] and arr[i] < suff_min[i + 1]) {
            ans++;
        }

        // maintaing mn
        mn = max(arr[i], mn);
    }
    return ans;
}

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) cin >> a;
    cout << getDefiniteFinds(arr) << endl;
}