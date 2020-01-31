#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp> 
using boost::multiprecision::cpp_dec_float_50;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double cpp_dec_float_50
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x) {for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

double fastpow(double a, int b) {
    double res = 1; while (b > 0) {
        if (b & 1) res = res * a;
        a = (a * a); b >>= 1;
    } return res;
}

float fastpow(int x, float a, int b) {
    float res = 1; while (b > 0) {
        if (b & 1) res = res * a;
        a = (a * a); b >>= 1;
    } return res;
}

vector<bool> vowels(128);

bool isAlice(string s) {
    int n = s.length();
    int prev = -2;
    if (!vowels[s[0]]) {
        prev = 0;
    }
    for (int i = 1; i < n; i++) {
        if (!vowels[s[i]]) {
            if ((i - prev) <= 2) return false;
            prev = i;
        }
    }
    return true;
}

int32_t main() { fastio;
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }
        
        vector<string> alice;
        vector<string> bob;
        for (int i = 0; i < n; i++) {
            if (isAlice(strs[i])) {
                alice.push_back(strs[i]);
            } else {
                bob.push_back(strs[i]);
            }
        }

        vector<int> freq(128);
        vector<int> count(128);
        for (auto a : alice) {
            vector<int> marked(128);
            for (auto x : a) {
                freq[x]++;
                if (!marked[x]) {
                    count[x]++;
                    marked[x] = true;
                }
            }
        }

        if (n <= 10) {
            float sca = 1;
            for (int i = 0; i < 128; i++) {
                if (freq[i] > 0) {
                    sca *= (((float) count[i]) / fastpow(0, freq[i], alice.size()));
                }
            }

            freq = vector<int>(128);
            count = vector<int>(128);
            for (auto a : bob) {
                vector<int> marked(128);
                for (auto x : a) {
                    freq[x]++;
                    if (!marked[x]) {
                        count[x]++;
                        marked[x] = true;
                    }
                }
            }
            float scb = 1;
            for (int i = 0; i < 128; i++) {
                if (freq[i] > 0) {
                    scb *= (((float) count[i]) / fastpow(0, freq[i], bob.size()));
                }
            }
            float res = (sca / scb);
            if (res > 1e7) {
                cout << "Infinity" << endl;
            } else {
                pout << res << endl;
            }
        } else {
            double sca = 1;
            for (int i = 0; i < 128; i++) {
                if (freq[i] > 0) {
                    sca *= (((double) count[i]) / fastpow(freq[i], alice.size()));
                }
            }

            freq = vector<int>(128);
            count = vector<int>(128);
            for (auto a : bob) {
                vector<int> marked(128);
                for (auto x : a) {
                    freq[x]++;
                    if (!marked[x]) {
                        count[x]++;
                        marked[x] = true;
                    }
                }
            }
            double scb = 1;
            for (int i = 0; i < 128; i++) {
                if (freq[i] > 0) {
                    scb *= (((double) count[i]) / fastpow(freq[i], bob.size()));
                }
            }
            double res = (sca / scb);
            if (res > 1e7) {
                cout << "Infinity" << endl;
            } else {
                pout << res << endl;
            }
        }
    }
    return 0;
}