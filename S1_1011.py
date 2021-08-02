#s1 1011 Fly me to the Alpha Centauri

T = int(input())

for i in range(T):
    cnt = 0
    x, y = map(int, input().split())
    while True:
        arr = [x + cnt - 1, x + cnt, x + cnt + 1]
        print(arr)
        for i in arr:
            if i == y:
                print(cnt)
                break

        cnt += 1

#1: 1
#2: 11
#3: 111
#4: 121
#5: 1211
#6: 1221
#7: 12211
#8: 12221
#9: 12321


