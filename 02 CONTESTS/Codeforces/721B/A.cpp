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
#define Mat vector<vector<int>>
#define getMat(aa, bb) vector<vector<int>>(aa, vector<int>(bb, 0))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int isPalin(string s) {
	int n = size(s);
	int count = 0;
	for (int i = 0; i < n / 2; i++) {
		count += (s[i] != s[n - i - 1]);
	}
	return count;
}

signed main() { fastio;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		int z = 0;
		for (auto x : s) {
			z += (x == '0');
		}
		if (z == 0) {
			cout << "DRAW" << endl;
		}
		else {
			int count = isPalin(s);
			if (count == 0) {
				if (z == 1) {
					cout << "BOB" << endl;
				}
				else {
					if (n & 1) {
						if (s[n / 2] == '0') {
							cout << "ALICE" << endl;
						} else {
							cout << "BOB" << endl;
						}
					} else {
						cout << "BOB" << endl;
					}
				}
			} else {
				if (z == 1) {
					cout << "ALICE" << endl;
				} 


				// z >= 2 and string not palindrome
				else {

					if (count == 1) {
						if (z == 2) {
							cout << "DRAW" << endl;
						} else {
							cout << "ALICE" << endl;
						}


						// if (n & 1) {
						// 	if (s[n / 2] == '0') {
						// 		cout << "DRAW" << endl;
						// 	} else {
						// 		cout << "ALICE" << endl;
						// 	}
						// } else {
						// 	cout << "ALICE" << endl;
						// }
					}




					else if (count == 2) {
						if (z < 4) {
							cout << "ALICE" << endl;
						} else {
							if (n & 1) {
								if (s[n / 2] == '0') {
									cout << "ALICE" << endl;
								} else {
									cout << "DRAW" << endl;
								}
							} else {
								cout << "DRAW" << endl;
							}
						}
					}





					else {
						cout << "ALICE" << endl;
					}
				}








			}
		}
	}
	return 0;
}