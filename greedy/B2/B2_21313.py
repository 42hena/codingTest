#B2 문어

N = int(input())
arr = []
if N % 2 == 0:
    arr = [1, 2] * (N //2)
else:
    arr = [1, 2] * (N //2) + [3]
print(*arr)
# 여기선 *arr이 중요한듯