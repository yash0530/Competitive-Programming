#include <bits/stdc++.h>
using namespace std;

int solve(string S) {
	string a, b;
	for (auto x : S) {
		if (x == '?') {
			a.push_back('A');
			b.push_back('C');
		} else {
			a.push_back(x);
			b.push_back(x);
		}
	}
	int mx = 0, sum = 0;
	for (auto x : a) {
		sum += (x == 'A');
		sum -= (x == 'C');
		mx = max(sum, mx);
	}
	sum = 0;
	for (auto x : b) {
		sum += (x == 'C');
		sum -= (x == 'A');
		mx = max(sum, mx);
	}
	return mx;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}