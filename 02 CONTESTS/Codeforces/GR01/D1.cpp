#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(int argc, char *a[])
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int>
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            b.push(x);
        }
        int count = 0;
        while (!a.empty() and !b.empty()) {
            cout << b.top() << " " << a.top() << endl;
            if (b.top() < a.top()) {
                count++;
                a.pop(); b.pop();
            } else {
                a.pop();
            }
        }
        cout << count << endl;
    }
}
