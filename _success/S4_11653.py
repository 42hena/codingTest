#S4 11653 소인수 분해

N = int(input())
if N == 1:
    exit()
i = 2
while (N != 1):
    if N % i == 0:
        print(i)
        N //= i
    else:
        i += 1