#G5 로봇 청소기 fail
dx = [0, -1, 0, 1] #북 서 남 동
dy = [-1, 0, 1, 0] #북 서 남 동

N, M  = map(int,input().split())

r, c, d = map(int, input().split())

area = []
for i in range(N):
    area.append(list(map(int, input().split())))
# 입력

cnt = 0
clean_cnt = 0


while True:
    if area[r][c] != 0:
        area[r][c] = 2  #현재 위치 청소
        clean_cnt += 1

    while area[r + dy[(d + 1) % 4]][c + dx[(d + 1) % 4]]:  #벽 또는 청소된 경우
        d += 1
        cnt += 1
        if cnt >= 4:
            if area[r - dy[d % 4]][c - dx[d % 4]] == 1:
                print(clean_cnt)
                exit()
            elif area[r - dy[d % 4]][c - dx[d % 4]] == 2:
                r -= dy[d % 4]
                c -= dx[d % 4]
                cnt = 0
                break
    if area[r + dy[(d + 1) % 4]][c + dx[(d + 1) % 4]] != 1 and area[r + dy[(d + 1) % 4]][c + dx[(d + 1) % 4]] != 2: #탐색 공간 있음
        r += dy[(d + 1) % 4]
        c += dx[(d + 1) % 4]
        d += 1
    print(r, c)

for i in range(N):
    for j in range(M):
        print(area[i][j], end= " ")
    print()
# 입력
