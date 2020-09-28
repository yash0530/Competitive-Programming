#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> arr(n);
		int p_count = 0, v_count = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n == 1) {
			cout << arr[0] << endl;
			while (q--) {
				int i, j;
				cin >> i >> j;
				cout << arr[0] << endl;
			}
			continue;
		}
		vector<bool> peaks(n);
		vector<bool> val(n);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (arr[i] > arr[i + 1]) {
					peaks[i] = true;
					p_count++;
				}
				if (arr[i] < arr[i + 1]) {
					val[i] = true;
					v_count++;
				}
			} else if (i == n - 1) {
				if (arr[i] > arr[i - 1]) {
					peaks[i] = true;
					p_count++;
				}
				if (arr[i] < arr[i - 1]) {
					val[i] = true;
					v_count++;
				}
			} else {
				if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
					peaks[i] = true;
					p_count++;
				}
				if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1]) {
					val[i] = true;
					v_count++;
				}
			}
		}
		int peak_sum = 0, valley_sum = 0;
		for (int i = 0; i < n; i++) {
			if (peaks[i])
				peak_sum += arr[i];
		}
		for (int i = 0; i < n; i++) {
			if (val[i])
				valley_sum += arr[i];
		}

		int ans;
		auto print_sum = [&]() {
			ans = peak_sum;
			if (v_count and (p_count > 1)) {
					if (v_count == 1) {
					ans -= valley_sum;
				} else {
					ans -= valley_sum;
					if (val[0]) {
						ans += arr[0];
					}
					if (val.back()) {
						ans += arr.back();
					}
				}
			}
			cout << ans << endl;
		};

		auto remove_from_peak = [&](int i) {
			if (peaks[i]) {
				peaks[i] = false;
				p_count--;
				peak_sum -= arr[i];
			}
		};

		auto remove_from_valley = [&](int i) {
			if (val[i]) {
				val[i] = false;
				v_count--;
				valley_sum -= arr[i];
			}
		};

		auto add_to_peak = [&](int i) {
			if ((i == 0)) {
				if ((arr[i] > arr[i + 1])) {
					if (!peaks[i]) {
						peaks[i] = true;
						p_count++;
						peak_sum += arr[i];
					}
				}
			} else if ((i == (n - 1))) {
				if ((arr[i] > arr[i - 1])) {
					if (!peaks[i]) {
						peaks[i] = true;
						p_count++;
						peak_sum += arr[i];
					}
				}
			} else {
				if ((arr[i] > arr[i - 1]) and (arr[i] > arr[i + 1])) {
					if (!peaks[i]) {
						peaks[i] = true;
						p_count++;
						peak_sum += arr[i];
					}
				}
			}
		};

		auto add_to_valley = [&](int i) {
			if ((i == 0)) {
				if ((arr[i] < arr[i + 1])) {
					if (!val[i]) {
						val[i] = true;
						v_count++;
						valley_sum += arr[i];
					}
				}
			} else if ((i == (n - 1))) {
				if ((arr[i] < arr[i - 1])) {
					if (!val[i]) {
						val[i] = true;
						v_count++;
						valley_sum += arr[i];
					}
				}
			} else {
				if ((arr[i] < arr[i - 1]) and (arr[i] < arr[i + 1])) {
					if (!val[i]) {
						val[i] = true;
						v_count++;
						valley_sum += arr[i];
					}
				}
			}
		};

		print_sum();

		while (q--) {
			int i, j;
			cin >> i >> j;
			i--; j--;

			// remove i and j form peaks and val if they exist
			remove_from_peak(i);
			remove_from_peak(j);
			remove_from_valley(i);
			remove_from_valley(j);
			

			// check for i - 1, i, i + 1 and j - 1, j, j + 1 if they are peak / val
			// and do the need full
			swap(arr[i], arr[j]);
			add_to_valley(i);
			add_to_peak(i);

			add_to_valley(j);
			add_to_peak(j);

			if (i) {
				remove_from_peak(i - 1);
				add_to_peak(i - 1);
				remove_from_valley(i - 1);
				add_to_valley(i - 1);
			}

			if (j) {
				remove_from_peak(j - 1);
				add_to_peak(j - 1);
				remove_from_valley(j - 1);
				add_to_valley(j - 1);
			}

			if (i != (n - 1)) {
				remove_from_peak(i + 1);
				add_to_peak(i + 1);
				remove_from_valley(i + 1);
				add_to_valley(i + 1);
			}

			if (j != (n - 1)) {
				remove_from_peak(j + 1);
				add_to_peak(j + 1);
				remove_from_valley(j + 1);
				add_to_valley(j + 1);
			}

			print_sum();
		}
	}
	return 0;
}