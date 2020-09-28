#include <stdio.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        int x;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (__builtin_popcount(x) % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
        for (int i = 0; i < q; i++) {
            scanf("%d", &x);
            if (__builtin_popcount(x) % 2 == 1) {
                printf("%d %d\n", odd, even);
            } else {
                printf("%d %d\n", even, odd);
            }
        }
    }
    return 0;
}