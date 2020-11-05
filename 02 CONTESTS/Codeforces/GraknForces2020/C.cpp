#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, l; cin >> n >> l;
		vector<int> arr(n + 2);
		arr[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		arr[n + 1] = l;
		n += 2;
		vector<array<double, 2>> car1(n), car2(n);
		double speed = 0, time = 0;
		int prev = 0;
		for (int i = 0; i < n; i++) {
			if (i)
				time += (arr[i] - prev) / speed;
			car1[i][0] = speed;
			car1[i][1] = time;
			speed++;
			prev = arr[i];
		}
		speed = 0, time = 0;
		prev = l;
		for (int i = n - 1; i >= 0; i--) {
			if (i != n - 1) 
				time += (prev - arr[i]) / speed;
			car2[i][0] = speed;
			car2[i][1] = time;
			speed++;
			prev = arr[i];
		}

		// [0] -> speed, [1] -> time
		for (int i = 0; i < n; i++) {
			if (car1[i][1] >= car2[i][1]) {
				double dist = arr[i] - arr[i - 1];
				double ans = 0;
				if (car1[i - 1][1] < car2[i][1]) {
					double tttt = car2[i][1] - car1[i - 1][1];
					dist -= tttt * (car1[i - 1][0] + 1);
					ans += tttt;
				} else {
					double tttt = car1[i - 1][1] - car2[i][1];
					dist -= tttt * (car2[i][0] + 1);
				}
				double tt = (dist / (car1[i - 1][0] + car2[i][0] + 2));
				ans += car1[i - 1][1] + tt;
				pout << ans << endl;
				break;
			}
		}
	}
	return 0;
}