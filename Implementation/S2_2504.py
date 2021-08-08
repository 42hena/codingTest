#S2 2504 실패...

string = input()

stack = []

if string[0] == ')':
    print("0")
    exit()
if string[0] == ']':
    print("0")
    exit()
#처음 에러 삭제

for i in range(len(string)):
    tmpsum = 0
    if string[i] == '(':
        stack.append(string[i])
    elif string[i] == '[':
        stack.append(string[i])
    elif string[i] == ')':
        while True:
            tmp = stack.pop()
            if tmp == "[": #에러
                print("0")
                exit()
            elif tmp == "(": #정상
                if tmpsum == 0:
                    stack.append(2)
                else:
                    stack.append(2*tmpsum)
                break
            else:            #정상
                tmpsum += tmp
    elif string[i] == ']':
        while True:
            tmp = stack.pop()
            if tmp == "(": #에러
                print("0")
                exit()
            elif tmp == "[": #정상
                if tmpsum == 0:
                    stack.append(3)
                else:
                    stack.append(3*tmpsum)
                break
            else:            #정상
                tmpsum += tmp
ans = 0
while len(stack) != 0:
    tmp = stack.pop()
    if tmp == '(':
        print("0")
        exit()
    elif tmp == '[':
        print("0")
        exit()
    else:
        ans += tmp
print(ans)
