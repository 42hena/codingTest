N, K = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))


dp = [0] * N

for i in range(1, N):
    if i == 0:
        if A[i] > B[i]:
            dp[i] = B[i]
            way = 1
        else:
            dp[i] = A[i]
            way = 0
    else:
        if way == 0:
            if A[i] < B[i] + K:
                dp[i] = A[i] + dp[i - 1]
                way = 0
            else:
                dp[i] = B[i] + K + dp[i - 1]
                way = 1
        else:
            if A[i] + K < B[i]:
                dp[i] = A[i] + K + dp[i - 1]
                way = 0
            else:
                dp[i] = B[i] + dp[i - 1]
                way = 1




# for i in range(N):
#     if i == 0:
#         if A[i] > B[i]:
#             dp[i] = B[i]
#             way = 1
#         else:
#             dp[i] = A[i]
#             way = 0
#     else:
#         if way == 0:
#             if A[i] < B[i] + K:
#                 dp[i] = A[i] + dp[i - 1]
#                 way = 0
#             else:
#                 dp[i] = B[i] + K + dp[i - 1]
#                 way = 1
#         else:
#             if A[i] + K < B[i]:
#                 dp[i] = A[i] + K + dp[i - 1]
#                 way = 0
#             else:
#                 dp[i] = B[i] + dp[i - 1]
#                 way = 1
# print(dp[N-1])
