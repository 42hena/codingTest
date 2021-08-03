N = int(input())
arr = [500, 100, 50, 10]
cnt = 0

for i in range(len(arr)):
    cnt += N // arr[i]
    N %= arr[i]
print(cnt)