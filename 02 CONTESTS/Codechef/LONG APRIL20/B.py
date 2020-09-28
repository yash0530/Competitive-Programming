def twoCount(x):
	x = abs(x)
	count = 0
	while x % 2 == 0 and x > 0:
		x >>= 1
		count += 1
	return count

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(i) for i in input().split()]
	total = 0
	H = {}
	H[0] = 1
	res = (n * (n + 1)) // 2;
	for i in range(n):
		total += twoCount(arr[i])
		if H.get(total - 1):
			res -= H[total - 1]
		if H.get(total):
			H[total] += 1
		else:
			H[total] = 1
	print(res)