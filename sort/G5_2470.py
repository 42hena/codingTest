N = int(input())

arr = list(map(int,input().split()))

i = 0
j = N - 1
min = 2000000000
arr.sort()
print(arr)
while i != j:
    print(i, j)
    add = abs(arr[i] + arr[j])
    if  add < min:
        min = add
        x = i
        y = j
    if abs(arr[i]) < abs(arr[j]):
        j -= 1
    else:
        i += 1
    
print(arr[x],arr[y])