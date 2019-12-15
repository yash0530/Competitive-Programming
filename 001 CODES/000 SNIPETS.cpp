#include <bits/stdc++.h>
using namespace std;

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int modInv(int a, int m) {
    int x, y;
    if (extended_euclidean(a, m, x, y) != 1)
        return -1;
    x = (x % m + m) % m;
    return x;
}

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

vector<int> primeFactors(int n) {
    vector<int> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (int d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    } return true;
}

int lcm(int a, int b) {
    return (int) (((double) a  / __gcd(a, b)) * b);
}

int lcmArray(vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    int ans = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}