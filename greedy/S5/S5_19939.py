#s5 19939
N, K = map(int, input().split())

minimum = K * (K + 1) // 2
if N < minimum:
    print(-1)
    exit()

minimum = N - (K - 1) * K //2
left = minimum % K
if left != 0:
    print(K)
else:
    print(K - 1)