#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> arr(n);
	for (int &a : arr) {
		cin >> a;
	}
	vector<pair<int, long long>> st;
	for (int &a : arr) {
		pair<int, long long> ar = { 1, a };
		while (!st.empty()) {
			if ((st.back().second * (st.back().first + ar.first)) >= ((ar.second + st.back().second) * st.back().first)) {
				ar.first += st.back().first;
				ar.second += st.back().second;
				st.pop_back();
			} else {
				break;
			}
		}
		st.push_back(ar);
	}
	cout << setprecision(10);
	for (pair<int, long long> &s : st) {
		double val = ((double) s.second) / (s.first);
		for (int i = 0; i < s.first; i++) {
			cout << val << "\n";
		}
	}
	return 0;
}