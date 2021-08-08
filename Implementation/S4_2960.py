#S4 2960
N, K = map(int, input().split())
# print(N, K)
cnt = 0
arr = [False for _ in range(N + 1)]

ans = 0
for i in range(2, N + 1):
    for j in range(i, N + 1, i):
        # print(i, j)
        if arr[j] == False:
            arr[j] = True
            cnt += 1
        if cnt == K:
            ans = j
            break
    if cnt == K:
        break
print(ans)