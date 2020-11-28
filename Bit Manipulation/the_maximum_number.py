from collections import defaultdict, OrderedDict

def get_sums_arr(arr):
    max_ele = max(arr)
    d = defaultdict(int)
    n = 1
    while n <= max_ele:
        for _, ele in enumerate(arr):
            d[n] += ele & n
        n <<= 1
    return sorted(d.values(), reverse=True)


def sol(arr, l):
    res = 1
    # p, i = 0, 0
    # arr.append(None)
    # while i < len(arr):
    #     if not l:
    #         break
    #     if arr[i] == arr[p]:
    #         i += 1
    #     else:
    #         # print(c)
    #         res *= (i-p)
    #         l -= 1
    #         p = i
    d = OrderedDict()
    for ele in arr:
        if ele in d:
            d[ele] += 1
        else:
            d[ele] = 1
    res = 1
    for i in d.keys():
        if not l:
            break
        res *= d[i]
        l -= 1

    if l:
        return -1

    return res    