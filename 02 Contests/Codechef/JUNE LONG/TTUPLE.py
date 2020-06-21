t = int(input())
for _ in range(t):
	a, b, c = (int(x) for x in input().split())
	p, q, r = (int(x) for x in input().split())

	d1 = p - a
	d2 = q - b
	d3 = r - c

	if (d1 == 0) and (d2 == 0) and (d3 == 0):
		print(0)
		continue

	if (d1 == 0) and (d2 == d3):
		print(1)
		continue

	if (d2 == 0) and (d1 == d3):
		print(1)
		continue

	if (d3 == 0) and (d2 == d1):
		print(1)
		continue

	if ((d1 == d2) and (d1 == d3)):
		print(1)
		continue

	if (d1 == d2) and (d1 == 0):
		print(1)
		continue

	if (d1 == d3) and (d1 == 0):
		print(1)
		continue

	if (d3 == d2) and (d3 == 0):
		print(1)
		continue

	b1 = False
	b2 = False
	b3 = False
	r1 = -1
	r2 = -1
	r3 = -1
	if (a != 0 and p % a == 0):
		b1 = True
		r1 = p // a

	if (b != 0 and q % b == 0):
		b2 = True
		r2 = q // b

	if (c != 0 and r % c == 0):
		b3 = True
		r3 = r // c

	if (b1 and b2 and b3) and ((r1 == r2) and (r1 == r3)):
		print(1)
		continue

	if (d1 == 0) and (b2 and b3) and (r2 == r3):
		print(1)
		continue

	if (d2 == 0) and (b1 and b3) and (r1 == r3):
		print(1)
		continue

	if (d3 == 0) and (b2 and b1) and (r2 == r1):
		print(1)
		continue

	if (d1 == d2):
		print(2)
		continue

	if (d2 == d3):
		print(2)
		continue

	if (d1 == d3):
		print(2)
		continue

	if (b1 and b2) and (r1 == r2):
		print(2)
		continue

	if (b1 and b3) and (r1 == r3):
		print(2)
		continue

	if (b3 and b2) and (r3 == r2):
		print(2)
		continue

	if (d1 == 0):
		print(2)
		continue

	if (d2 == 0):
		print(2)
		continue

	if (d3 == 0):
		print(2)
		continue

	print(3)