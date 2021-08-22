import math

N = int(input())

i = 1
while True:
    if N <= 1+3*(i-1)*(i):
        print(i)
        break
    i += 1

# val = 1+ ((3+math.sqrt(9-12*(1-N))//2))
# print(val)1
