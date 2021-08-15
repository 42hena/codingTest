N = int(input())

dp = [0] * (N + 1)
array = [0]
for i in range(N):
    array.append(float(input()))
# print(array)

# 시간초과
# for i in range(1, N + 1):
#     maxval = 0
#     val = 1
#     for j in range(i, N + 1):
#         val *= array[j]
#         if maxval < val:
#             maxval = val
#     dp[i] = round(maxval,3)
# print(max(dp))