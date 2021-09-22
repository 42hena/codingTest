import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
x, y = map(int, input().split())
m = int(input())
graph = [[0]]
for _ in range(n):
    graph.append([])
for _ in range(m):
    a, b = map(int, input().split())
    # print(a,b )
    graph[a].append(b)
    graph[b].append(a)

# print(graph)

queue = deque([x])
visited = [False] * (n+1)
cnt = 0
while len(queue) > 0:
    for _ in range(len(queue)):
        value = queue.popleft()
        if value == y:
            print(cnt)
            exit()
        # print("v",value)
        visited[value] = True
        # print(value)
        for i in range(len(graph[value])):
            if not visited[graph[value][i]]:
                queue.append(graph[value][i])
    cnt+=1

print(-1)