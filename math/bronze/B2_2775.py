
apart = [[0]*14 for _ in range(15)]

for i in range(14):
    apart[0][i] = i + 1

for i in range(1, 15):
    for j in range(14):
        if j == 0:
            apart[i][0] = 1
        else:
            apart[i][j] = apart[i][j - 1] + apart[i - 1][j]
for _ in range(int(input())):
    k = int(input())
    n = int(input())
    print(apart[k][n - 1])