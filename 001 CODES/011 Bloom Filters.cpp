// PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1370

#include <bits/stdc++.h>
using namespace std;

#define int long long

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

#define M1 (int) (1e9 + 23)
// #define M2 (int) (1e9 + 9)
// #define M3 (int) (1e9 + 23)
#define offset (int) (1e9 + 57)

// Multiple bloom filters
// bitset<M1> b1;
// bitset<M2> b2;
// bitset<M3> b3;
bitset<M1> b;

// exponents
vector<int> exponents1(27, 1);
vector<int> exponents2(27, 1);
// vector<int> exponents3(27, 1);

void precomputeExponents() {
    for (int i = 1; i < 27; i++) {
        exponents1[i] = (exponents1[i - 1] * 27) % M1;
        // exponents2[i] = (exponents2[i - 1] * 27) % M2;
        // exponents3[i] = (exponents3[i - 1] * 27) % M3;
    }
}

// hash functions: BASED ON FREQUENCY
int h1(char x, int curr = offset) {
    return (curr + exponents1[(x - 'a' + 1)]) % M1;
}

// int h2(char x, int curr = offset) {
//     return (curr + exponents2[(x - 'a' + 1)]) % M2;
// }

// int h3(char x, int curr = offset) {
//     return (curr + exponents3[(x - 'a' + 1)]) % M3;
// }

// add to bitset
void add(int H1) {
    // b1.set(H1);
    // b2.set(H2);
    // b3.set(H3);

    b.set(H1);
    // b.set(H2);
}

// test for presence
bool test(int H1) {
    // return b1.test(H1) and b2.test(H2) and b3.test(H3);
    return b.test(H1);
}

int32_t main() {

    precomputeExponents();

    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length(), n2 = s2.length();
    for (int i = 0; i < n1; i++) {
        int H1 = h1(s1[i]);
        add(H1);
        for (int j = i + 1; j < n1; j++) {
            H1 = h1(s1[j], H1);
            add(H1);
        }
    }
    int res = 0;
    for (int i = 0; i < n2; i++) {
        int length = 1;
        int H1 = h1(s2[i]);
        if (test(H1)) {
            res = max(res, length);
        }
        for (int j = i + 1; j < n2; j++) {
            length++;
            H1 = h1(s2[j], H1);
            if (test(H1)) {
                res = max(res, length);
            }
        }
    }
    cout << res << endl;
    return 0;
}