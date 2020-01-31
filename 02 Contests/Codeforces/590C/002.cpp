#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> locs;
    deque<int> q;
    for (int i = 0, j = 0; i < n; i++) {
        if (locs.find(arr[i]) == locs.end()) {
            if (q.size() == k) {
                locs.erase(q.back());
                q.pop_back();
            }
            locs.insert(arr[i]);
            q.push_front(arr[i]);
            j++;
        }
    }

    cout << q.size() << endl;
    for (auto x : q) {
        cout << x << " ";
    } cout << endl;

    return 0;
}