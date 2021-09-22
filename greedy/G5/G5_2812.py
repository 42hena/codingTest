
#success
N, K = map(int, input().split())
string = list(input())
# print(string)

i = 0
cnt = 0

stack = []

for i in range(len(string)):
    if i != 0:
        while stack:
            if cnt == K:
                break
            value =  stack.pop()
            if value < string[i]:
                cnt += 1
            else:
                stack.append(value)
                break
    stack.append(string[i])

while cnt != K:
    stack.pop()
    cnt += 1

for i in stack:
    print(i, end="")
print()