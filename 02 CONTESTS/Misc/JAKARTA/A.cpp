#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    vector<int> arr(x);
    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < x; i++) {
        cout << arr[(i + 1) % x] << " ";
    }
    cout << endl;
}