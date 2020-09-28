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

const int maxN = 1e6 + 5;
int tree[maxN];

void update(int index, int val) {
    while (index < maxN) {
        tree[index] += val;
        index += (index & -index);
    }
}

int read(int index) {
    int sum = 0;
    while (index) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

int sum (int left, int right) {
	int ans = 0;
	ans -= read(left - 1);
	ans += read(right);
	return ans;
}

struct Event {
	int point, type, b, c;
};

bool cust(Event &a, Event &b) {
	return make_pair(a.point, a.type) < make_pair(b.point, b.type);
}

int32_t main() { fastio;
	int n, m;
	cin >> n >> m;
	vector<Event> events;
	for (int i = 0; i < n; i++) {
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		events.pb({ x1, 1, y, x2 });
		events.pb({ x2, 3, y, x1 });
	}
	for (int i = 0; i < m; i++) {
		int x, y1, y2;
		cin >> x >> y1 >> y2;
		events.pb({ x, 2, y1, y2 });
	}
	events.pb({ (int)1e6, 2, 0, (int)1e6 });
	sort(events.begin(), events.end(), cust);

	memset(tree, 0, sizeof tree);
	update(1, 1);
	update((int)(1e6 + 1), 1);

	int ans = 0;
	set<int> unbounded;
	for (auto event : events) {
		
		// horizontal start
		if (event.type == 1) {
			if (event.point == 0) {
				update(event.b + 1, 1);
			} else {
				unbounded.insert(event.b);
			}
		}
		
		// horizontal end
		if (event.type == 3) {
			if (sum(event.b + 1, event.b + 1)) {
				update(event.b + 1, -1);
			} else {
				unbounded.erase(event.b);
			}
		}

		// vertical line
		if (event.type == 2) {
			ans += (sum(event.b + 1, event.c + 1) - 1);
			if (event.b == 0) {
				while (!unbounded.empty() and (*unbounded.begin() <= event.c)) {
					update((*unbounded.begin()) + 1, 1);
					unbounded.erase(unbounded.begin());
				}
			} else {
				while (!unbounded.empty() and (*unbounded.rbegin() >= event.b)) {
					update((*unbounded.rbegin()) + 1, 1);
					unbounded.erase(*unbounded.rbegin());
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}