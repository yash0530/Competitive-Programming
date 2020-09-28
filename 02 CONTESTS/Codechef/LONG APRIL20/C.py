HELL = 998244353

def fastpow(a, b, m):
    res = 1
    a %= m
    while b > 0:
        if (b & 1):
            res = (res * a) % m
        a = (a * a) % m
        b >>= 1
    return res

def XOR(a, b):
	res = []
	res.append(a[0] * b[3] + a[3] * b[0] + a[1] * b[2] + a[2] * b[1])
	res.append(a[3] * b[1] + a[0] * b[2] + a[1] * b[3] + a[2] * b[0])
	res.append(a[3] * b[2] + a[0] * b[1] + a[1] * b[0] + a[2] * b[3])
	res.append(a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3])
	for i in range(4):
		res[i] = res[i] % HELL
	return res

def AND(a, b):
	res = []
	res.append(a[0] * b[0])
	res.append(a[0] * b[1] + a[1] * b[0] + a[1] * b[1])
	res.append(a[0] * b[2] + a[2] * b[0] + a[2] * b[2])
	res.append(a[3] * b[3] + a[3] * b[0] + a[3] * b[1] + a[3] * b[2] + a[0] * b[3] + a[1] * b[3] + a[1] * b[2] + a[2] * b[3] + a[2] * b[1])
	for i in range(4):
		res[i] = res[i] % HELL
	return res

def OR(a, b):
	res = []
	res.append(a[3] * b[0] + a[0] * b[0] + a[0] * b[1] + a[0] * b[2] + a[0] * b[3] + a[1] * b[0] + a[1] * b[2] + a[2] * b[0] + a[2] * b[1])
	res.append(a[3] * b[1] + a[1] * b[3] + a[1] * b[1])
	res.append(a[3] * b[2] + a[2] * b[3] + a[2] * b[2])
	res.append(a[3] * b[3])
	for i in range(4):
		res[i] = res[i] % HELL
	return res

def get(a, op, b):
	if op == '&':
		return AND(a, b)
	elif op == '|':
		return OR(a, b)
	return XOR(a, b)

def evaluate(s):
	stack = []
	for x in s:
		if x == '#':
			stack.append([1, 1, 1, 1])
		elif x == '&' or x == '|' or x == '^':
			stack.append(x)
		elif x ==')':
			a = stack.pop()
			op = stack.pop()
			b = stack.pop()
			stack.append(get(a, op, b))
	return stack[0]

t = int(input())
for _ in range(t):
	s = input()
	count = 0
	for x in s:
		if x == '#':
			count += 1
	den = fastpow(fastpow(4, count, HELL), HELL - 2, HELL)
	num = evaluate(s)
	num2 = [ num[3], num[0], num[1], num[2] ]
	for n in num2:
		print((n * den) % HELL, end = " ")
	print()