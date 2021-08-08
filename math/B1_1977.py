import math
M = int(input())
N = int(input())

ans_sum = 0
ans_min = 0
arr = []
for i in range(M, N + 1):
    if pow(int(math.sqrt(i)), 2) == i:
        arr.append(i)
if len(arr) != 0:
    ans_min = arr[0]
    ans_sum = sum(arr)
    print(ans_sum)
    print(ans_min)
else:
    print(-1)