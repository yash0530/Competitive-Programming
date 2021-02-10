#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		if (k >= 10101) {
			cout << -1 << endl;
			continue;
		}
		k = min(10101, k);
		int last = -1;
		for (int i = 0; i < k; i++) {
			bool done = false;
			for (int i = 0; i < (n - 1); i++) {
				if (arr[i] < arr[i + 1]) {
					arr[i]++;
					done = true;
					last = i + 1;
					break;
				}
			}
			if (!done) {
				last = -1;
				break;
			}
		}
		cout << last << endl;
	}
}