N = int(input())

arr = []
for i in range(N*3):
    arr.append(list(map(int, input().split())))
j = 1
for i in range(1, N + 1):
    print(j, j + 1, j + 2)
    j += 3
