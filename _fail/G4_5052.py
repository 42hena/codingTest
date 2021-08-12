T = int(input())

for t in range(T):
    N = int(input())
    arr = []
    for n in range(N):
        arr.append(input())
    
    arr.sort()
    print(arr)
    item = arr[0]
    cnt = 0
    for i in range(1, N):
        if item in arr[i]:
            cnt += 1
            break
    if cnt >= 1:
        print("NO")
    else:
        print("YES")