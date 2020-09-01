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

    public:
        Trie() {
            root = new node();
        }

        void _insert(string key) {
            node *pCrawl = root;
            int len = key.length();
            for (int i = 0; i < len; i++) {
                int index = key[i] - 'a';
                if (!pCrawl->children[index]) {
                    pCrawl->children[index] = new node();
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
};