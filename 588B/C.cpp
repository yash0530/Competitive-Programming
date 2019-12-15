#include <bits/stdc++.h>
using namespace std;

int countSame(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> I;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(I));
    return I.size();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> *G = new vector<int>[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (n == 7) {
        int max_val = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 7; j++) {
                int val = countSame(G[i], G[j]);
                max_val = max(max_val, m - val);
            }
        } 
        cout << max_val << endl;
    } else {
        cout << m << endl;
    }
}