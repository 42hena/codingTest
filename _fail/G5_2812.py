N, K = map(int, input().split())

string = list(input())
cnt = 0
i = 0
while len(string) - 1 != i:
    if int(string[i]) < int(string[i + 1]):
        string.pop(i)
        cnt += 1
        if cnt == K:
            break
        if i != 0:
            i -= 1
            continue
        else:
            continue
    i += 1

for i in range(K-cnt):
    string.pop()

for i in range(len(string)):
    print(string[i], end="")
