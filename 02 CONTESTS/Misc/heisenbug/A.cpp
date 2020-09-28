#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int32_t main() { fastio;
	int t; cin >> t;
	int n, x;
	while (t--) {
		cin >> n;
		x = (int)sqrt(n);
		cout << x << "\n";
	}
	return 0;
}