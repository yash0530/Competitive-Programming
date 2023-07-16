#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		int res = 0, pref = 0;
		for (auto x : arr) {
			pref = max(pref + x, x);
			res = max(res, pref);
		}
	}
}