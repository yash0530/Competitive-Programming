s = input().split()
a = int(s[0])
b = int(s[1])
c = int(s[2])
if c < (a + b):
    print("No")
elif 4 * (a * b) < (c - a - b) * (c - a - b):
    print("Yes")
else:
    print("No")