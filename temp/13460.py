import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
Map = []
for _ in range(n):
    Map.append(list(map(str, input().rstrip())))

print(Map)
visited_R = [[False]*m for _ in range(n)]
visited_B = [[False]*m for _ in range(n)]
rx = 0
ry = 0

bx = 0
by = 0

ox = 0
oy = 0


dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

for i in range(n):
    for j in range(m):
        if Map[i][j] == 'R':
            rx = i
            ry = j
        if Map[i][j] == 'B':
            bx = i
            by = j
        if Map[i][j] == 'O':
            ox = i
            oy = j

def BFS():
    queue = deque([[rx, ry, 0, -1, 'R'], ])
    
    while queue:
        print(queue)
        x, y, d, cnt = queue.popleft()

        if x == ox and y == oy:
            return cnt
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if not visited_R[nx][ny] and (Map[nx][ny] == '.' or Map[nx][ny] == 'O'):
                visited_R[nx][ny] = True
                if k != d:
                    queue.append([nx, ny, k, cnt + 1])
                else:
                    queue.append([nx, ny, k, cnt])
    return -1

def RisPossible():
    for k in range(4):
        nx = rx + dx[k]
        ny = ry + dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if not visited_R[nx][ny] and (Map[nx][ny] == '.' or Map[nx][ny] == 'O'):
            return True
    return False
Rflag = RisPossible()
BFS()


##########
#B#...##.#
#R..#.##.#
#####.##.#
#......#.#
#.######.#
#.#.....##
#.#.#.#3##
#...#.O#.#
##########