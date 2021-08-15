def test(N, x, y, move_cnt, cnt):
    if move_cnt == K:
        return cnt
    move_cnt += 1
    print("hi")
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >= 1 and nx <= N and ny >= 1 and ny <= N:
            cnt += test(N, nx, ny, move_cnt, cnt)
            print(cnt)

    return cnt

N, x, y, K = map(int, input().split())

dx = [-1, -2, -2, -1,  1,  2,  2, 1]
dy = [2,  1, -1, -2, -2, -1, 1, 2]

cnt = 0
print(test(N, x, y, 0, cnt))
# print(cnt/8/K)
