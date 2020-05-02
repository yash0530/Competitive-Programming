#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()
    .time_since_epoch()).count();
}

int val(string &s, int i) {
    return (s[i] - 'A');
}

#define ALPHA 26

struct TrieNode {
    vector<TrieNode *> next;
    int freq;
    TrieNode() {
        freq = 0;
        next = vector<TrieNode *>(ALPHA, NULL);
    }
};

class Trie {
    private:
        TrieNode *root;
        int res, k;

        bool __isLeaf(TrieNode *node) {
            for (int i = 0; i < ALPHA; i++) {
                if (node->next[i] != NULL) {
                    return false;
                }
            }
            return true;
        }

        int __dfs(TrieNode *curr, int l) {
            if (__isLeaf(curr)) {
                res += (curr->freq / k) * l;
                return curr->freq % k;
            }
            int sum = 0;
            for (int i = 0; i < ALPHA; i++) {
                if (curr->next[i] != NULL) {
                    sum += curr->next[i]->freq;
                }
            }
            sum = curr->freq - sum;
            for (int i = 0; i < ALPHA; i++) {
                if (curr->next[i] != NULL) {
                    sum += __dfs(curr->next[i], l + 1);
                }
            }
            res += (sum / k) * l;
            return sum % k;
        }

    public:
        Trie(int k) {
            root = new TrieNode();
            res = 0;
            this->k = k;
        }

        void _add(string s) {
            TrieNode *crawl = root;
            root->freq++;
            for (int i = 0; i < s.length(); i++) {
                if (crawl->next[val(s, i)] == NULL) {
                    crawl->next[val(s, i)] = new TrieNode();
                }
                crawl->next[val(s, i)]->freq++;
                crawl = crawl->next[val(s, i)];
            }
        }

        int _dfs() {
            __dfs(root, 0);
            return res;
        }
};

int32_t main() { fastio;
    time_t start = now();

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        vector<int> diff;
        int n, k;
        cin >> n >> k;
        Trie trie(k);
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            trie._add(s);
        }
        cout << "Case #" << i << ": " << trie._dfs() << endl;
    }

    cerr << "TIME => " << now() - start << endl;
    return 0;
}