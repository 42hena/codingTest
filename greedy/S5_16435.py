N, L = map(int, input().split())

fruit_height = list(map(int, input().split()))
fruit_height.sort()
for i in range(N):
    if L >= fruit_height[i]:
        L += 1
    else:
        break
print(L)