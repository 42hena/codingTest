import sys
input = sys.stdin.readline
n = int(input())
data = []
for i in range(n):
    data.append(list(map(str,input().split())))
    data[i][1] = int(data[i][1])
    data[i][2] = int(data[i][2])
    data[i][3] = int(data[i][3])
data.sort(key=lambda x: (x[3], x[2], x[1]))
print(data[n - 1][0])
print(data[0][0])