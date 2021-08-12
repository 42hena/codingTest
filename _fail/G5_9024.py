N, K = map(int,input().split())

arr = list(map(int,input().split()))

i = 0
j = N - 1
min = 200000000
arr.sort()
print(arr)
while i != j:
    # print(i, j)
    add = abs(arr[i] + arr[j] - K)
    if  add < min :
        min = add
        x = i
        y = j
    if arr[i] + arr[j] - K > 0:
        j -= 1
    else:
        i += 1
print(arr[x],arr[y])
value = arr[x] + arr[y]
count = 0
i = 0
j = N - 1
while i != j:
    if arr[i] + arr[j] == value:
        count += 1
    if arr[i] + arr[j] - K > 0:
        j -= 1
    else:
        i += 1
print(count)