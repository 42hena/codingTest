#실패

import sys
T = int(input())
for t in range(T):
    N = int(input())
    arr = []
    for i in range(N):
        A, B = map(int,sys.stdin.readline().split())
        arr.append([A, B])
    arr.sort(key = lambda x: (-x[0]))
    print(arr)
    
    count = 0
    for i in range(N - 1):
        if arr[i][1] > arr[i + 1][1]:
            continue
        count += 1
    print(count + 1)
    # count = 0
    # for i in range(N):
    #     # print("i:",arr[i])
    #     for j in range(i + 1, N):
    #         # print("j:",arr[j])
    #         if arr[i][0] > arr[j][0] and arr[i][1] > arr[j][1]:
    #             break
    #         if j == N - 1:
    #             count += 1
    # print(count + 1)

    