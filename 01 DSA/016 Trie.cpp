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
};