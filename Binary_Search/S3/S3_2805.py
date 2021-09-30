# 범위 한번 생각 하기

N, M = map(int, input().split())
array = list(map(int, input().split()))

left, right = 0, max(array)

ans = 0
while left <= right:
    mid = (left + right) // 2
    total = 0
    for h in array:
        dis = h - mid
        if dis >= 0:
            total += dis
    # print(total, mid)
    if total >=M:
        left = mid + 1
        ans = mid
    else:
        right = mid - 1
print(ans)