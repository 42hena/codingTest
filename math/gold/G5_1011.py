import math

for _ in range(int(input())):
    x, y = map(int, input().split())
    value = y - x


    Rounds = round(math.sqrt(value))
    
    if pow(Rounds,2)>= value:
        print(Rounds*2 -1)
    else:
        print(2*Rounds)