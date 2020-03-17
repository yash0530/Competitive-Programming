t = int(input())
for i in range(t):
    s = input()
    n = int(s.split()[0])
    m = int(s.split()[1])
    f = input().split()
    for i in range(n):
        f[i] = int(f[i])
    
    p = input().split()
    for i in range(n):
        p[i] = int(p[i])

    H = {}
    for i in range(n):
        if H.get(f[i]):
            H[f[i]] += p[i]
        else:
            H[f[i]] = p[i]
    res = 100000000000000
    for h in H.values():
        res = min(res, h)
    print(res)