import random
a = []
for i in range(1, 1001):
	a.append(i)
random.shuffle(a)
for x in a:
	print(x, end = " ")
print()