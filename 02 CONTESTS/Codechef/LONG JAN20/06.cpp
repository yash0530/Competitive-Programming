#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int val(string &s, int i) {
    return (s[i] - 'a') * 26 + (s[s.length() - 1 - i] - 'a');
}

#define ALPHA 676

struct TrieNode {
    vector<TrieNode *> next;
    vector<int> freq;
    TrieNode() {
        freq = vector<int>(ALPHA);
        next = vector<TrieNode *>(ALPHA, NULL);
    }
};

class Trie {
    private:
        TrieNode *root;
        void __dfs(TrieNode *curr, int &res, int l) {
            for (int i = 0; i < ALPHA; i++) {
                if (curr->next[i] != NULL) {
                    res += (curr->freq[i] / 2) * ((l + 1) * (l + 1) - l * l);
                    __dfs(curr->next[i], res, l + 1);
                }
            }
        }

    public:
        Trie() {
            root = new TrieNode();
        }

        void _add(string s) {
            TrieNode *crawl = root;
            for (int i = 0; i < s.length(); i++) {
                if (crawl->next[val(s, i)] == NULL) {
                    crawl->next[val(s, i)] = new TrieNode();
                }
                crawl->freq[val(s, i)]++;
                crawl = crawl->next[val(s, i)];
            }
        }

        int _dfs() {
            int res = 0;
            __dfs(root, res, 0);
            return res;
        }
};

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; Trie trie;
        for (int i = 0; i < n; i++) {
            cin >> s;
            trie._add(s);
        }
        cout << trie._dfs() << endl;
    }
    return 0;
}