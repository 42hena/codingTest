import math
A, B, V = map(int, input().split())

h = 0
cnt = 0

print(math.ceil(1 + (V - A) / (A - B)))

# A + (A - B) * cnt > V
#math.ceil을 활용하자