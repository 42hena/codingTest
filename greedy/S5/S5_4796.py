#s5 4796 캠핑
i = 1
while True:
    L, P, V = map(int, input().split())
    if L == P == V == 0:
        break
    cnt = V // P
    leftDay = V % P
    # print(cnt, leftDay)
    if leftDay > L:
        leftDay = L
    print("Case %d: %d" %(i, L * cnt + leftDay))
    i += 1
