HELL = int(1e9 + 7)
import math

def getNumbers(n):
    v = set();
    v.add(1);
    x = int(math.sqrt(n)) + 1
    for i in range(2, x): 
        j = i * i; 
        v.add(j); 
        while (j * i <= n): 
            v.add(j * i); 
            j = j * i;
    return list(v); 

ns = []
max_n = 0
for i in range(int(input())):
    n = int(input())
    ns.append(n)
    max_n = max(n, max_n)

x = getNumbers(max_n)
for n in ns:
    res = 0
    for i in x:
        res = (res + ((n // i) * i)) % HELL
    print(res)