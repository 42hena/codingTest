T = int(input())

for i in range(T):
    a, b = map(int, input().split())

    cala, calb = a, b
    while calb != 0:
        cala, calb = calb, cala%calb
    print(a*b//cala, cala)
    