// CSES Collecting Numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &a : arr) {
		cin >> a;
	}
	set<int> ss;
	int count = 0;
	for (auto a : arr) {
		ss.insert(a);
		if (ss.find(a - 1) != ss.end()) {
			count++;
		}
	}
	cout << n - count << endl;
}