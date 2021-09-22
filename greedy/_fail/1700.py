# 1700 멀티탭 스케줄링
N, K = map(int, input().split())
array = list(map(int, input().split()))

count = [0] * (K + 1)
tmp = []

for i in array:
    if i not in tmp and len(tmp) != K:
        tmp.append(i)
        count[i] -= 1
    elif i not in tmp and len(tmp) == K:
        for j in tmp:
            count
        tmp.append(i)
