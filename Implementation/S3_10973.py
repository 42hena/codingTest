#S3 10973 
#실패
import sys
from itertools import permutations
input = sys.stdin.readline

#itertool을 잘 사용해야할 듯
N = int(input())

input_val = tuple(map(int, input().split()))
sort_data = sorted(input_val)
nPr = list(permutations(sort_data))

if nPr[0] == input_val:
    print(-1)

for i in range(1, len(nPr)):
    if input_val == nPr[i]:
        print(*nPr[i - 1])


# for i in range(1, len(nPr)):
#     if input_val == nPr[i]:
#         print(*nPr[i - 1])


# for i in range(len(nPr)):
#     arr.append([])
#     for j in range(len(nPr[i])):
#         arr[i].append(nPr[i][j])

# if arr[0] == input_val:
#     print(-1)

# for i in range(1, len(arr)):
#     # print(i, arr[i])
#     if arr[i] == input_val:
#         print(*arr[i - 1])