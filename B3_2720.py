#B3 2720 세탁소 사장 동혁
T = int(input())

kind = [25, 10, 5, 1]
for i in range(T):
    C = int(input())
    count = [0 for _ in range(4)]
    for j in range(4):
        count[j] = C // kind[j]
        C %= kind[j]

    print(count[0], count[1], count[2], count[3])

#음 배수관계 아니긴 한데 왜 일까? 
#추측: 500의 250보다 크면 dp아니면 다이나믹이 되는거 같음