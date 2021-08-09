#S5 8979 올림픽 success >> fail
import sys
input = sys.stdin.readline
N, K = map(int, input().split())

arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

arr.sort(key=lambda x: (-x[1], -x[2], -x[3]))
# print(arr)

rank = []
want_index = 0
for i in range(N):
    cnt = 0
    if arr[i][0] == K:
        want_index = i
    # print(arr[i][1], arr[i][2],arr[i][3])
    for j in range(N):
        if (arr[i][1] > arr[j][1]):
            # print(1)
            cnt += 1
        elif (arr[i][1] == arr[j][1] and arr[i][2] > arr[j][2]):
            # print(2)
            cnt += 1
        elif ( arr[i][1] == arr[j][1] and arr[i][2] == arr[j][2] and arr[i][3] >= arr[j][3]):
            # print(3)
            cnt += 1
        # print("val",cnt)
    rank.append(cnt)
# print(rank)

print(N-rank[want_index] +1)