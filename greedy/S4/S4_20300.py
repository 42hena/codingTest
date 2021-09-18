N = int(input())

array = list(map(int, input().split()))
array.sort()
ans = []
if N % 2 == 1:
    for i in range(N//2 + 1):
        if i == N//2:
            ans.append(array[N - 1])
            continue
        ans.append(array[i] + array[N - i - 2])
    print(max(ans))
else:
    for i in range(N//2 + 1):
        ans.append(array[i] + array[N - i - 1])
    print(max(ans))