#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int maxN = 2e5 + 5;
int par[maxN], size[maxN];

inline void precomp(int v) {
    for (int i = 0; i <= v; i++) {
        size[i] = 1;
        par[i] = i;
    }
}

bool _union(int a, int b) {
	while (par[a] != a) {
        par[a] = par[par[a]];
        a = par[a];
    }
    while (par[b] != b) {
        par[b] = par[par[b]];
        b = par[b];
    }
    if (a == b) return false;
    
    if (size[a] < size[b]) {
        par[a] = b;
        size[b] += size[a];
    } else {
        par[b] = a;
        size[a] += size[b];
    }
    return true;
}

vector<vector<int>> poss;
vector<int> curr;
void genPoss(int i, int &d) {
	if (i == d) {
		vector<int> inv = curr;
		for (auto &i : inv) i *= -1;
		if (find(poss.begin(), poss.end(), inv) == poss.end())
			poss.pb(curr);
		return;
	}
	curr.pb(1);
	genPoss(i + 1, d);
	curr.pop_back();
	curr.pb(-1);
	genPoss(i + 1, d);
	curr.pop_back();
}

inline int dot(vector<int> &a, vector<int> &b) {
	int sum = 0;
	for (int i = 0; i < size(a); i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

inline int manhattan(vector<int> &a, vector<int> &b) {
	int sum = 0;
	for (int i = 0; i < size(a); i++) {
		sum += abs(a[i] - b[i]);
	}
	return sum;
}

int32_t main() { fastio;
	int n, d;
	cin >> n >> d;
	getMat(points, n, d, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> points[i][j];
		}
	}
	genPoss(0, d);
	int x = 1 << (d - 1);
	getMat(okay, x, n, 0);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < n; j++) {
			okay[i][j] = dot(poss[i], points[j]);
		}
	}
	int64_t ans = 0;
	precomp(n);
	priority_queue<array<int, 3>> pq;
	for (int i = 0; i < x; i++) {
		int mx = max_element(okay[i].begin(), okay[i].end()) - okay[i].begin();
		int mn = min_element(okay[i].begin(), okay[i].end()) - okay[i].begin();
		for (int i = 0; i < n; i++) {
			int curr = manhattan(points[i], points[mx]);
			int curr2 = manhattan(points[i], points[mn]);
			if (curr > curr2)
				pq.push({ curr, i, mx });
			else
				pq.push({ curr2, i, mn });
		}
	}
	while (!pq.empty()) {
		array<int, 3> edge = pq.top(); pq.pop();
		if (_union(edge[1], edge[2])) {
			ans += edge[0];
		}
	}
	cout << ans << endl;
	return 0;
}