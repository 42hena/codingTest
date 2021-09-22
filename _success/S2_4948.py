#S2 4948 베트르랑 공준
import sys

while True:
    n = sys.stdin.readlines()
    print(n)
    if n == 0:
        break

# arr = [False for _ in range(N + 1)]

# for i in range(2, N + 1):
#     for j in range(2 * i, N + 1, i):
#         if arr[j] == True:
#             continue
#         arr[j] = True

# if M == 1:
#     M = 2
# ans = []
# for i in range(M, N + 1):
#     if (arr[i] == False):
#         ans.append(i)
# #print(arr)
# if len(ans) == 0:
#     print(-1)
# else:
#     print(sum(ans))
#     print(ans[0])
# # valueError 입력 한번에 해서 틀렸음
# #시간초과 