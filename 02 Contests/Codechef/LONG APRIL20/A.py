import math

t = int(input())
for i in range(t):
	x, k = (int(i) for i in input().split())
	count = 0
	for i in range(2, int(math.sqrt(x)) + 1):
		while (x > 1) and (x % i == 0):
			x //= i
			count += 1
	if x > 1:
		count += 1
	if (count >= k):
		print(1)
	else:
		print(0)