N = int(input())

inf = list(map(int, input().split()))

left = inf.pop(0)
right = inf.pop(N - 2)
# print(left,right,inf)

for i in range(N - 2):
    if i == N - 3:
        left -= 1
        right -= 1
        break
    if left > right:
        left -= 1
    else :
        right -= 1
    # print(left,right)
print(max(left,right))