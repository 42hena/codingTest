#B1 17224

N, L, K = map(int, input().split())

test = []
for i in range(N):
    test.append(list(map(int, input().split())))
test.sort(key = lambda x: (x[1], x[0]))
count = 0

cnt = 0
for i in range(N):
    if cnt >= K:
        break
    if test[i][1] <= L:
        count += 140
        cnt += 1
    elif test[i][0] <= L:
        count += 100
        cnt +=1
print(count)