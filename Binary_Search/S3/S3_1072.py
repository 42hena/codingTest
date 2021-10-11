# 실패

from math import floor
X, Y = map(int, input().split())

Z = floor(Y/X*100)
# print(Z)
l, r = 0, int(1e9)


if Z >=99:
    print(-1)
    exit(0)
ans = 0
# if x <= 0:
#     print(-1)
#     exit(0)
while l <= r:
    m = (l + r) // 2
    rate = floor((Y+m) * 100/(X+m))
    print(rate,l, r, m)
    if rate >= Z:
        r = m - 1
        ans = m
    else:
        l = m + 1
        
    
print(ans)