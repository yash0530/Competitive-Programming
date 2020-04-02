/*
ID: yashjai4
TASK: ride
LANG: C++14              
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // ofstream cout ("ride.out");
    // ifstream cin ("ride.in");
    string s, k; cin >> s >> k;
    int res = 1, rek = 1;
    for (auto x : s) {
    	res = (res * (x - 'A' + 1)) % 47;
    }
    for (auto x : k) {
    	rek = (rek * (x - 'A' + 1)) % 47;
    }
    if (res == rek) {
    	cout << "GO" << endl;
    } else {
    	cout << "STAY" << endl;
    }
    return 0;
}