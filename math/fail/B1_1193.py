import math
X = int(input())
N = (-1 + math.sqrt(1 + 8 * (1-X))/2)
print(N)
print(X - N*(N + 1) // 2)
# print(X*(X+1)//2)
# dx = [1, -1, 0, 1]
# dy = [-1, 1, 1, 0]
# cnt = 1
# i = 1
# j = 1
# while True:
#     if cnt == X:
#         break
#     if (i + j) % 2 == 0 and i == 1:
#         i += dx[2]
#         j += dy[2]
#     elif (i + j) % 2 != 0 and j == 1:
#         i += dx[3]
#         j += dy[3]
#     elif (i + j) % 2 == 0:
#         i += dx[1]
#         j += dy[1]
#     elif (i + j) % 2 != 0:
#         i += dx[0]
#         j += dy[0]
#     cnt += 1
# print("%d/%d"%(i,j))