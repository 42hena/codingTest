#S4 16956 늑대와 양
def mapping(graph):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(R):
        for j in range(C):
            if graph[i][j] == "W":
                for k in range(4):
                    nx = i + dx[k]
                    ny = j + dy[k]
                    if nx < 0 or nx >=R or ny < 0 or ny >= C:
                        continue
                    if graph[nx][ny] == '.':
                        graph[nx][ny] = 'D'
                    elif graph[nx][ny] == 'S':
                        return False
    return True

R, C = map(int, input().split())


graph = []

for i in range(R):
    graph.append(list(map(str, input())))
# print(graph)

if mapping(graph) == True:
    print(1)
    for i in range(R):
        for j in range(C):
            print(graph[i][j], end="")
        print()
else:
    print(0)