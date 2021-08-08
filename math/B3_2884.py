#B3 2884
H, M = map(int,input().split())
# print(H, M)

if M <45:
    M -= 45
    M %= 60
    H -= 1
else:
    M -= 45
H %= 24
print(H, M)