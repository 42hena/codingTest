import sys
import math

while True:
    n = int(input())
    if n == -1:
        break
    s = set()
    for i in range(1, int(math.sqrt(n)+ 1)):
        # print("과영",i)
        if n % i == 0:
            s.add(i)
            s.add(n//i)
    s.remove(n)
    # print(s)
    # print(sum(s))
    

    if sum(s) == n:
        tmp = sorted(s)
        print("%d = " %(n), end="")
        for j in range(len(tmp)):
            if j != len(tmp) - 1:
                print("%d + " %(tmp[j]), end="")
            else:
                print(tmp[j])
    else:
        print("%d is NOT perfect." %(n))
    # print(s.sort())