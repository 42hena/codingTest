
N = int(input())
val = int(input())

graph = [[0]*N for _ in range(7)]

cnt = 1
i = N//2
j = N//2
# while True:
graph[i][j] = cnt
cnt += 1
print(graph)