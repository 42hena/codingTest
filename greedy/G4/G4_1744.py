import sys
input = sys.stdin.readline

N = int(input())
Sum = 0
plus = []
minus = []
for _ in range(N):
    value = int(input())
    if value > 0:
        if value == 1:
            Sum += 1
        else:
        # heapq.heappush(plus, (-value, value))
            plus.append(value)
    else:
        # heapq.heappush(minus, value)
        minus.append(value)

plus.sort(reverse=True)
minus.sort()



plus_len = len(plus)
if plus_len % 2 == 0:
    for i in range(0, plus_len, 2):
        Sum += plus[i] * plus[i + 1]
else:
    for i in range(0, plus_len - 1, 2):
        Sum += plus[i] * plus[i + 1]
    Sum += plus[plus_len - 1]
    
minus_len = len(minus)
if minus_len % 2 == 0:
    for i in range(0, minus_len, 2):
        Sum += minus[i] * minus[i + 1]
else:
    for i in range(0, minus_len - 1, 2):
        Sum += minus[i] * minus[i + 1]
    Sum += minus[minus_len - 1]
print(Sum)