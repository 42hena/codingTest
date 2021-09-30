import sys

input = sys.stdin.readline
K, N = map(int, input().split())
array = []
for _ in range(K):
    array.append(int(input()))

ans = 0
l, r = 1, max(array)
while l <= r:
    mid = (l + r) // 2
    total = 0
    for x in array:
        total += x // mid
    # print(mid, total)
    if total < N:
        r = mid - 1
    else:
        l = mid + 1
        ans = mid        
print(ans)

