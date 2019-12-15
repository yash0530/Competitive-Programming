#include <bits/stdc++.h>
using namespace std;

int main() {

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    
    if (a1 + a2 == a3 + a4) {
        cout << "YES" << endl;
    } else if (a1 + a3 == a2 + a4) {
        cout << "YES" << endl;
    } else if (a1 + a4 == a2 + a3) {
        cout << "YES" << endl;
    } else if (a1 == a2 + a3 + a4) {
        cout << "YES" << endl;
    } else if (a2 == a1 + a3 + a4) {
        cout << "YES" << endl;
    } else if (a3 == a1 + a2 + a4) {
        cout << "YES" << endl;
    } else if (a4 == a1 + a2 + a3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}