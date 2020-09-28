#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define HELL 998244353
#define int long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int n, sqn;
const int maxN = 100005;
int fact[maxN], invFact[maxN];

bool comp(vector<int> a, vector<int> b) {
    if ((a[1] / sqn) == (b[1] / sqn)) {
        return a[2] < b[2];
    }
    return (a[1] / sqn) < (b[1] / sqn);
}

void cc(vector<int> &arr) {
    map<int, int> M;
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (M.find(arr[i]) != M.end()) {
            arr[i] = M[arr[i]];
        } else {
            M[arr[i]] = val;
            arr[i] = val++;
        }
    }
}

int nck(int n, int k) {
    return (invFact[n - k] * ((fact[n] * invFact[k]) % HELL)) % HELL;
}

class Freq {

    private:
        struct Node {
            Node *prev = NULL, *next = NULL;
            int val, freq;
            Node(int val) {
                this->val = val;
                freq = 0;
            }
        };
        vector<Node *> present;
        Node *head, *tail;
        int size;

    public:
        Freq(int n) {
            present.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                present[i] = new Node(i);
            }
            size = 0;
            head = tail = NULL;
        }

        void inc(int val) {
            present[val]->freq++;
            if (present[val]->freq == 1) {
                if (head) {
                    tail->next = present[val];
                    present[val]->prev = tail;
                    tail = present[val];
                } else {
                    tail = head = present[val];
                }
            }
        }

        void dec(int val) {
            present[val]->freq--;
            if (present[val]->freq == 0) {
                if (present[val] == head and present[val] == tail) {
                    head = tail = NULL;
                } else if (present[val] == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (present[val] == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    (present[val]->next)->prev = present[val]->prev;
                    (present[val]->prev)->next = present[val]->next;
                }
                present[val]->next = present[val]->prev = NULL;
            }
        }

        int cal(int xr) {
            int res = 0;
            Node *crawl = head;
            while (crawl) {
                int x = xr ^ crawl->val;
                if (x < crawl->val) {
                    res = (res + (crawl->freq * nck(crawl->val, x))) % HELL;
                }
                crawl = crawl->next;
            }
            return res;
        }
};

int32_t main() { fastio;
    fact[0] = 1; invFact[0] = 1;
    for (int i = 1; i < maxN; i++) {
        fact[i] = (i * fact[i - 1]) % HELL;
        invFact[i] = fastpow(fact[i], HELL - 2, HELL);
    }

    int t; cin >> t;
    while (t--) {

        cin >> n;
        sqn = floor(sqrt(n));
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cc(arr);
        int q; cin >> q;
        vector<vector<int>> Q(q, { 0, 0, 0 });
        for (int i = 0; i < q; i++) {
            Q[i][0] = i;
            cin >> Q[i][1] >> Q[i][2];
            Q[i][1]--; Q[i][2]--;
        }
        sort(Q.begin(), Q.end(), comp);

        Freq f(n);
        vector<int> freq(maxN), res(q);
        int start = 0, end = 0;
        freq[arr[start]]++;
        int xr = freq[arr[start]];
        f.inc(freq[arr[start]]);
        for (auto x : Q) {
            int l = x[1], r = x[2];
            if (end > r) {
                while (end != r) {
                    f.dec(freq[arr[end]]);
                    freq[arr[end]]--;
                    f.inc(freq[arr[end]]);
                    xr ^= freq[arr[end]];
                    xr ^= freq[arr[end]] + 1;
                    end--;
                }
            }
            if (end < r) {
                while (end != r) {
                    end++;
                    xr ^= freq[arr[end]];
                    xr ^= freq[arr[end]] + 1;
                    f.dec(freq[arr[end]]);
                    freq[arr[end]]++;
                    f.inc(freq[arr[end]]);
                }
            }
            if (start > l) {
                while (start != l) {
                    start--;
                    xr ^= freq[arr[start]];
                    xr ^= freq[arr[start]] + 1;
                    f.dec(freq[arr[start]]);
                    freq[arr[start]]++;
                    f.inc(freq[arr[start]]);
                }
            }
            if (start < l) {
                while (start != l) {
                    f.dec(freq[arr[start]]);
                    freq[arr[start]]--;
                    f.inc(freq[arr[start]]);
                    xr ^= freq[arr[start]];
                    xr ^= freq[arr[start]] + 1;
                    start++;
                }
            }
            res[x[0]] = f.cal(xr);
        }
        for (auto r : res) {
            cout << r << endl;
        }
    }
    return 0;
}