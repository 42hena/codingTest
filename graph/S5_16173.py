def search(x, y):
    # print("now",x,y)
    if x == N - 1 and y == N - 1:
        print("HaruHaru")
        exit()
    val = graph[x][y]
    if val == 0:
        return False
    # print(val)
    for i in range(2):
        nx = x + dx[i] * val
        ny = y + dy[i] * val
        if nx >= N or ny >= N:#이게 왜 가능할까
            continue
        else:
            search(nx, ny)
    return False

N = int(input())
graph = []

dx = [0, 1]
dy = [1, 0]
for i in range(N):
    graph.append(list(map(int, input().split())))
# print(graph)

if search(0, 0) == False:
    print("Hing")