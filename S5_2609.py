#S5 2609 gcd, lsm

M, N = map(int, input().split())

min  = min(M, N)
for i in range(1, min + 1):
    if (M % i == 0 and N % i == 0):
        gcd = i
lsm = M // gcd * N // gcd * gcd
print(gcd)
print(lsm)
