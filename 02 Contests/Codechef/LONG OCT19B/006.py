def val(x):
    if (ord(x) >= 65):
        return ord(x) - 55
    else:
        return ord(x) - 48

def min_base(x):
    b = val(x[0]) + 1
    for i in range(1, len(x)):
        b = max(b, val(x[i]) + 1)
    return b

def evaluate(b, x):
    res = 0
    base = 1
    for i in range(len(x) - 1, -1, -1):
        res += val(x[i]) * base
        base *= b
    return res

t = int(input())
for i in range(t):
    n = int(input())
    bases = []
    nums = []
    for j in range(n):
        base, num = input().split()
        base = int(base)
        bases.append(base)
        nums.append(num)

    index = -1
    res = -1
    for j in range(n):
        if bases[j] != -1:
            index = j
            res = evaluate(bases[j], nums[j])
            break

    possible = True
    if (index != -1):
        for j in range(n):
            if (j != index):
                if (bases[j] != -1):
                    if (res != evaluate(bases[j], nums[j])):
                        possible = False
                        break
                else:
                    mb = min_base(nums[j])
                    found = False
                    for k in range(mb, 37, 1):
                        if (res == evaluate(k, nums[j])):
                            found = True
                            break
                    if (found == False):
                        possible = False
                        break
    else:
        possible = False
        mb = min_base(nums[0])

        for j in range(mb, 37, 1):
            temp_res = evaluate(j, nums[0])
        
            poss = True
            for k in range(1, n):
                m_base = min_base(nums[k])
                found = False
                for l in range(m_base, 37, 1):
                    if (temp_res == evaluate(l, nums[k])):
                        found = True
                        break
                if (found == False):
                    poss = False
                    break
        
            if (poss):
                res = temp_res
                possible = True
                break

    if (possible and res <= 1e12):
        print(res)
    else:
        print(-1)