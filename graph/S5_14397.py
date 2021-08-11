#S4 16956 늑대와 양
def mapping(graph):
    dx1 = [1, -1, 0, 0, 1, -1]
    dy1 = [0, 0, -1, 1, -1, -1]
    dx2 = [1, -1, 0, 0, 1, -1]
    dy2 = [0, 0, -1, 1, 1, 1]
    lenght = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == ".":
                for k in range(6):
                    if i % 2 == 0:
                        # print(j)
                        nx = i + dx1[k]
                        ny = j + dy1[k]
                    else:
                        nx = i + dx2[k]
                        ny = j + dy2[k]
                    if nx < 0 or nx >= N or ny < 0 or ny >= M:
                        continue
                    if graph[nx][ny] == '#':
                        # print(nx, ny)
                        lenght += 1
                # print()
                # print("val",i,j,lenght)
                    
    return True, lenght

N, M = map(int, input().split())


graph = []

for i in range(N):
    graph.append(list(map(str, input())))
# print(graph)

isTrue, lenght = mapping(graph)
if isTrue == True:
    print(lenght)