t = int(input())
for _ in range(t):
	n, k = (int(x) for x in input().split())
	a = [int(x) for x in input().split()]
	d = {}
	for i in range(n):
		d[a[i]] = i + 1
	
	res = []
	for i in range(n):
		if (a[i] != i + 1):
			x = i + 1
			y = d[d[i + 1]]
			z = d[i + 1]
			if (x == y):
				if (x + 1 == z and z == n):
					x = n
					y = n - 1
					z = n - 2
				elif (x + 1 == z):
					y = z + 1
				else:
					y = z - 1

			res.append([ x, y, z ])
			aval = a[x - 1]
			bval = a[y - 1]
			cval = a[z - 1]
			a[x - 1] = cval
			a[y - 1] = aval
			a[z - 1] = bval
			d[aval] = y
			d[bval] = z
			d[cval] = a

	if (len(res) > k):
		print(-1)
		continue

	print(len(res))
	for r in res:
		for x in r:
			print(x, end = " ")
		print()