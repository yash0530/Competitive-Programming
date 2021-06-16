// CSES Missing Coin Sum
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	long long int ans = 1;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (arr[i] > ans) break;
		else {
			ans += arr[i];
		}
	}
	cout << ans << endl;
}