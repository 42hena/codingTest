#s4 통계학 2108
N = int(input())

arr = list(int(input()) for _ in range(N))
arr_count = [0 for _ in range(N)]
# print(arr)
arr.sort()
# print(arr)

arr_sum = sum(arr)
print(round(arr_sum / N))
print(arr[N//2])

for i in range(N):
    cnt = 0
    for j in range(i, N):
        if arr[i] == arr[j]:
            cnt += 1
    arr_count[i] = cnt
# print(arr_count)
max_num = max(arr_count)
max_count = arr_count.count(max_num)
cnt = 0
index = 0
for i in range(N):
    if max_num == arr_count[i]:
        cnt += 1
    if cnt == 2:
        index = i
        break
print(arr[index])

print(arr[N - 1] - arr[0])