a, b, c = map(int, input().split())
value = max(a, b, c)
dp = [[0] * (value + 1) for _ in range(4)]
print(dp)