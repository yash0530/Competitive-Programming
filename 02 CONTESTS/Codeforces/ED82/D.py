from math import log2

for t in range(int(input())):
    n, m = map(int, input().split())
    c = [0] * 61
    s = 0
    for x in map(int, input().split()):
        c[int(log2(x))] += 1
        s += x

    if s < n:
        print(-1)
        continue

    i, res = 0, 0
    while i < 60:
        if (1 << i) & n != 0:
            if c[i] > 0:
                c[i] -= 1
            else:
                while i < 60 and c[i] == 0:
                    i += 1
                    res += 1
                c[i] -= 1
                continue
        c[i + 1] += c[i] // 2
        i += 1

    print(res)