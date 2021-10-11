N = int(input())
array = list(map(int, input().split()))
x = int(input())

l, r = 0, max(array)
ans = 0
while l <= r:
    m = (l + r) // 2
    total = 0
    for money in array:
        if money <= m:
            total += money
        else:
            total += m
    # print(m, total)
    if total > x:
        r = m - 1
    else:
        l = m + 1
        ans = m
print(ans)