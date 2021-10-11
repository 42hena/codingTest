import sys
input = sys.stdin.readline
N, C = map(int, input().split())
array = []

for _ in range(N):
    array.append(int(input()))

array.sort()
# print(array)

l, r = 0, max(array)
# print(l, r)

ans = 0
while l <= r:
    m = (l + r) // 2
    first = array[0]
    delcnt = 0
    min = int(1e9)
    for i in range(1, N):
        dis = array[i] - first
        if dis >= m:
            if min > dis:
                min = dis
            first = array[i]
        else:
            delcnt += 1
    # print("test",l,r,m, delcnt, min)
    if delcnt > N - C:
        r = m - 1
    else:
        l = m + 1
        ans = min
print(ans)