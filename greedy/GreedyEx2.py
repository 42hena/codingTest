N, K = map(int, input().split())


result = 0
while True:
    target = (N // K) * K
    result += (N - target)
    n = target

    if N < K:
        break
    result += 1
    N //= K
result += (N -1)
print(result)       #log 시간 복잡도?

#
#cnt = 0
# while N != 1:
#     print(N)
#     if N % K == 0:
#         N //= K
#         cnt += 1
#     elif N // K == 0:
#         N -= 1
#         cnt += 1
#     elif N % K != 0:
#         cnt += N - N // K * K
#         N = N // K * K
# print(cnt)