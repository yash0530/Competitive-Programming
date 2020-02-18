print(100)
a = 1000
for i in range(100):
    print(a)
    for i in range(1, a):
        print(f'{i} {i + 1}')
    for i in range(a):
        print(1, end = " ")
    print()