# 11000 강의실 배정
N = int(input())

classTime = []
for _ in range(N):
    classTime.append(list(map(int, input().split())))
count = [0] * (N + 1)

classTime.sort(key=lambda x: (x[0], x[1]))


for i in range(len(classTime)):
    start, end = classTime[i]
    cnt = 0
    for j in range(i + 1, len(classTime)):
        if end == classTime[j][0]:
            end = classTime[j][1]
            cnt += 1
            
