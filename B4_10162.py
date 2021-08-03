#B4 106162 전자레인지

Time = [300, 60, 10]

T = int(input())

if T % Time[2] != 0:
    print(-1)
else:
    count = [0 for _ in range(3)]
    for i in range(3):
        count[i] += T // Time[i]
        T %= Time[i]
    print(count[0], count[1], count[2])