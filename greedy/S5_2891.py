#s5 2891 캬악과 강풍

N, S, R = map(int, input().split())
break_team = list(map(int, input().split()))
more_team = list(map(int, input().split()))

now = [0 for _ in range(N + 2)]

for i in break_team:
    now[i] = 1
for i in more_team:
    if now[i] == 1:
        now[i] = 0
    else:
        now[i] = 2

for i in range(1, N + 1):
    if now[i] == 1:
        if now[i - 1] == 2:
            now[i - 1] = 0
            now[i] = 0
        elif now[i + 1] == 2:
            now[i + 1] = 0
            now[i] = 0
# print(now)
cnt = 0
for i in range(1, N + 1):
    if now[i] == 1:
        cnt += 1
print(cnt)
# True False로 하면 값이 더럽게 된다. 