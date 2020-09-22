#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int ld = 0, rd = n * (n - 1) / 2;
		for (int i = 1, cd = 0; i <= n; ++i) {
			if (!(i & (i - 1))) ++cd;
			ld += cd - 1;
		}
		if (!(ld <= d && d <= rd)) {
			cout << "NO" << endl;
			continue;
		}
	
		vector<int> par(n);
		iota(par.begin(), par.end(), -1);
		
		vector<int> cnt(n, 1);
		cnt[n - 1] = 0;
		
		vector<int> bad(n);
		
		vector<int> dep(n);
		iota(dep.begin(), dep.end(), 0);
		int cur = n * (n - 1) / 2;
		int count = 0;
		while (cur > d) {
			count++;
			int v = -1;
			for (int i = 0; i < n; ++i) {
				if (!bad[i] && cnt[i] == 0 && (v == -1 || dep[v] > dep[i])) {
					v = i;
				}
			}
			assert(v != -1);
			int p = -1;
			for (int i = 0; i < n; ++i) {
				if (cnt[i] < 2 && dep[i] < dep[v] - 1 && (p == -1 || dep[p] < dep[i])) {
					p = i;
				}
			}
			if (p == -1) {
				bad[v] = 1;
				continue;
			}
			assert(dep[v] - dep[p] == 2);
			--cnt[par[v]];
			--dep[v];
			++cnt[p];
			par[v] = p;
			--cur;
		}
		cerr << count << endl;
		cout << "YES" << endl;
		for (int i = 1; i < n; ++i) cout << par[i] + 1 << " ";
		cout << endl;
	}
		
	return 0;
}