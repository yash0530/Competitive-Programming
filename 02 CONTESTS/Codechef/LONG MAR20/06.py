import sys

t = int(input())

def printRes(res):
    print(2, end=" ")
    for r in res:
        print(r, end=" ")
    print()
    sys.stdout.flush()
    x = input()
    return x

def ask(x1, x2, y):
    print(f'1 {x1} {x2} {y}')
    sys.stdout.flush()
    h = int(input())
    return h

for _ in range(t):
    s = input().split()
    n = int(s[0])
    m = int(s[1])
    k = int(s[2])
    q = int(s[3])
    queries = []
    for _ in range(q):
        x = input().split()
        queries.append([int(x[0]), int(x[1])])

    if (n == 20000):
        res = [m - 1] * q
        printRes(res)
    else:
        res = []
        for i in range(q):
            res.append(max(ask(queries[i][0], queries[i][1], 500000000), 0))
        printRes(res)