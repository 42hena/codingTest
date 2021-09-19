N, M = map(int, input().split())
J = int(input())
array = []
for _ in range(J):
    array.append(int(input()))

now = 1

cnt = 0
for apple in array:
    # print("apple:",apple)
    if now + M - 1 < apple:
        cnt += apple - (now + M - 1)
        now =  apple - (M - 1)
        
    elif now > apple:
        cnt += now - apple
        now = apple
        
    # print("val",now, cnt)
print(cnt)
