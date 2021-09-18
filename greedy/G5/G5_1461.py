N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
plus = []
minus = []
for i in arr:
    if i > 0 :
        plus.append(i)
    else:
        minus.append(i)

ans = 0
# for i in range(10, 0, -1):
#     print(i)
for i in range(0, len(minus), M):
    ans += minus[i] * 2

plus.sort(reverse=True)
for i in range(0, len(plus), M):
    ans += plus[i] * 2
# for i in range(len(plus) - 1, -1, -M):
#     ans += plus[i] * 2

print(ans - max(abs(arr[0]),abs(arr[N-1])))