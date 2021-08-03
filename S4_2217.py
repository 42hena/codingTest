#s4 2217 로프
N = int(input())
arr = []
for i in range(N):
    n = int(input())
    arr.append(n)

arr.sort()
maxVal = 0
for i in range(N):
    arr[i] = arr[i] * (N - i)
    if maxVal < arr[i]:
        maxVal = arr[i]
print(maxVal)