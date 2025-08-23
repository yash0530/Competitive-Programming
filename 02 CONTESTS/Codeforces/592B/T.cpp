#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<string> queries = {"+2", "+3", "+9", "+4", "+-0", "--2", "+6", "+1", "-3", "+12", "+7", "+3", "+3"};
    int diff = 3;

    map<int, int> mp;
    int ans = 0;
    for (auto q : queries) {
        if (q[0] == '+') {
            q = q.substr(1, q.size() - 1);
            int val = stoi(q);
            mp[val]++;
            ans += mp[val - diff] * mp[val + diff];
            ans += mp[val - diff] * mp[val - 2 * diff];
            ans += mp[val + diff] * mp[val + 2 * diff];
        } else {
            q = q.substr(1, q.size() - 1);
            int val = stoi(q);
            ans -= mp[val] * (mp[val - diff] * mp[val + diff]);
            ans -= mp[val] * (mp[val - diff] * mp[val - 2 * diff]);
            ans -= mp[val] * (mp[val + diff] * mp[val + 2 * diff]);
            mp[val] = 0;
        }
        cout << ans << " ";
    } cout << endl;
}
