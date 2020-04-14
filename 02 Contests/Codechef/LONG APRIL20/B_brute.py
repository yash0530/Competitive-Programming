t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(i) for i in input().split()]

	res = 0
	for i in range(n):
		curr = 1
		for j in range(i, n):
			curr *= arr[j]
			curr = curr % 4
			if curr != 2:
				res += 1
	print(res)