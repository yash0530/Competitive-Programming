t = int(input())

moves = [
    [1, 1],
    [2, 2],
    [3, 1],
    [4, 2],
    [5, 1],
    [6, 2],
    [7, 1],
    [8, 2],
    [7, 3],
    [8, 4],
    [7, 5],
    [8, 6],
    [7, 7],
    [8, 8],
    [7, 7],
    [6, 8],
    [5, 7],
    [4, 8],
    [3, 7],
    [2, 8],
    [1, 7],
    [2, 6],
    [1, 5],
    [2, 4],
    [1, 3],
    [2, 2],
    [3, 3],
    [4, 4],
    [5, 3],
    [6, 4],
    [5, 5],
    [4, 6],
    [3, 5],
    [5, 7],
    [6, 6]]

def solve():
    s = input().split()
    r = int(s[0])
    c = int(s[1])

    for i in range(35):
        if moves[i][0] == r and moves[i][1] == c:
            print(35)
            for j in range(35):
                x = (i + j) % 35
                print(f'{moves[x][0]} {moves[x][1]}')
            return

for _ in range(t):
    solve()