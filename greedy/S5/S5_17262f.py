N = int(input())
arr = []
time = [False for _ in range(100000)]
min = 100001
max = 0
for i in range(N):
    s, e = map(int, input().split())
    arr.append([s, e])
    if min > s:
        min = s
    if max < e:
        max = e
    for j in range(s, e):
        time[j] = True
cnt = 0
for i in range(min, max):
    if time[i] == False:
        cnt += 1
    
print(cnt)