HELL = 1000000007

def fastpow(a, b, m):
    res = 1
    a %= m
    while b > 0:
        if (b & 1):
            res = (res * a) % m
        a = (a * a) % m
        b >>= 1
    return res

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    den = fastpow((n + 1) * n // 2, HELL - 2, HELL)
    num = 0
    prev = 0
    curr = 0
    count = 0
    H = {}
    i = n - 1
    while i >= 0:
        if s[i] == '*':
            curr = prev
        elif s[i] == ')':
            curr = n - i
            if H.get(count + 1):
                curr += H.get(count + 1)
            count -= 1
        else:
            if H.get(count + 1):
                curr += H.get(count + 1)
            count += 1
        H[count] = curr
        num  = (num + curr) % HELL
        prev = curr
        curr = 0
        i -= 1
    print((num * den) % HELL)