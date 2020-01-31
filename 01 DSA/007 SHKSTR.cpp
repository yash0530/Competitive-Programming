#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

struct node {
    node *children[ALPHABET_SIZE];
    bool isEndOfWord; 
};

class Trie {
    private:
        node *root;
        node *__getNode() {
            node *temp = new node();
            temp->isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                temp->children[i] = NULL;
            }
            return temp;
        }

    public:
        Trie() {
            root = __getNode();
        }

        void _insert(string key) {
            node *pCrawl = root;
            int len = key.length();
            for (int i = 0; i < len; i++) {
                int index = key[i] - 'a';
                if (!pCrawl->children[index]) {
                    pCrawl->children[index] = __getNode();
                }
                pCrawl = pCrawl->children[index];
            }
            pCrawl->isEndOfWord = true;
        }

        bool _search(string key) {
            node *pCrawl = root;
            int len = key.length();
            for (int i = 0; i < len; i++) {
                int index = key[i] - 'a';
                if (!pCrawl->children[index]) {
                    return false;
                }
                pCrawl = pCrawl->children[index];
            }
            return (pCrawl != NULL && pCrawl->isEndOfWord);
        }

        string _walkTrie(string key) {
            string ans;
            node *pCrawl = root;
            int len = key.length();

            for (int i = 0; i < len; i++) {
                int index = key[i] - 'a';
                if (!pCrawl->children[index]) break;

                pCrawl = pCrawl->children[index];
                ans += key[i];
            }

            if (pCrawl != NULL && pCrawl->isEndOfWord)
                return ans;
            else {
                while (!pCrawl->isEndOfWord) {
                    for (int i = 0; i < 26; i++) {
                        if (pCrawl->children[i] != NULL) {
                            pCrawl = pCrawl->children[i];
                            ans += char(i + 97);
                            break;
                        }
                    }
                }
                return ans;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string strs[n];
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    int q; cin >> q;
    vector<pair<int, pair<int, string>>> queries;
    for (int i = 0; i < q; i++) {
        int r; string p; cin >> r >> p;
        queries.push_back({ r, { i, p } });
    }
    sort(queries.begin(), queries.end());

    vector<pair<int, string>> answers;
    Trie trie;
    int prev = 0;
    for (int i = 0; i < q; i++) {
        int lim = queries[i].first;
        for (int j = prev; j < lim; j++) {
            trie._insert(strs[j]);
        }
        prev = lim - 1;
        answers.push_back({ queries[i].second.first, trie._walkTrie(queries[i].second.second) });
    }
    sort(answers.begin(), answers.end());

    for (int i = 0; i < q; i++) {
        cout << answers[i].second << endl;
    }
}