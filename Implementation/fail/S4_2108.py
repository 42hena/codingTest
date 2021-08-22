# S4 2108 통계학
import sys
input = sys.stdin.readline

array = []
N = int(input())
cnt = [1] * N
for i in range(N):
    array.append(int(input()))
array.sort()
print(array)

print(sum(array)//N)
print(array[N//2])
i = 0

while i < N - 1:
    if i == 0:
        for j in range(i + 1, N):
            if array[i] == array[j]:
                cnt[i] += 1
            else:
                break
    else:
        if array[i - 1] == array[i]:
            continue
        for j in range(i + 1, N):
            if array[i] == array[j]:
                cnt[i] += 1
            else:
                break
    i += 1
print(min(cnt))
print(array[N - 1] - array[0])