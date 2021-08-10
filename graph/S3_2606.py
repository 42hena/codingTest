from collections import deque

def bfs(graph, V, visited, cnt):
    queue = deque([V])
    visited[V] = True
    while queue:
        x = queue.popleft()
        for i in graph[x]:
            if visited[i] == False:
                cnt += 1
                queue.append(i)
                visited[i] = True
    print(cnt)


computer_num = int(input())
network_num = int(input())

# print(computer_num, network_num)

graph = []
visited = [False for _ in range(computer_num + 1)]

for i in range(computer_num + 1):
    graph.append([])

for i in range(network_num):
    V1, V2 = map(int, input().split())
    graph[V1].append(V2)
    graph[V2].append(V1)
# print(graph)

cnt = 0
bfs(graph, 1, visited, cnt)
