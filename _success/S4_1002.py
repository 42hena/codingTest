#S4 1002 터렛(스타 ㅋㅋ)
import math
T = int(input())
for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = math.sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
    r = r1 + r2
    # print("d = ", d, "r = ",r)
    if (x1 == x2 and y1 == y2):
        if r1 == r2:
            print(-1)
        else:
            print(0)
    #원이 같은 경우
    else:
        if d < r:
            print(2)
        elif (d == r):
            print(1)
        elif(d > r):
            print(0)
