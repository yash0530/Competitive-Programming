#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    string s; cin >> s;

    if (n == 0) {
        return 0;
    }
    if (k == 0) {
        cout << s << endl;
        return 0;
    }

    if (n == k and k == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    if (s[0] != '1') {
        s[0] = '1';
    } else {
        k = min(n, k + 1);
    }

    int i = 1;
    while (i < min(k, n)) {
        if (s[i] == '0') {
            k++;
        } else {
            s[i] = '0';
        }
        i++;
    }
    cout << s << endl;
}