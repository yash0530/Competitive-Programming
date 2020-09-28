#include <bits/stdc++.h>
using namespace std;

#define endl "\n"in
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1) {
			cout << "1\n1 1" << endl;
		} else if (n % 2 == 0) {
			cout << n / 2 << endl;
			for (int i = 1; i <= n; i += 2) {
				cout << 2 << " " << i << " " << i + 1 << endl;
			}
		} else {
			cout << n / 2 << endl;
			cout << 3 << " " << 1 << " " << 2 << " " << n << endl;
			for (int i = 3; i <= (n - 1); i += 2) {
				cout << 2 << " " << i << " " << i + 1 << endl;
			}
		}
	}	    
    return 0;
}
