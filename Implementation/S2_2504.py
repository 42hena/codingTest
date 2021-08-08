#S2 2504 실패...

string = input()

stack = []
ans = 0

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
                print("닥쳐")
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
                print("닥쳐")
                exit()
            elif tmp == "[": #정상
                if tmpsum == 0:
                    stack.append(3)
                else:
                    stack.append(3*tmpsum)
                break
            else:            #정상
                tmpsum += tmp
print(sum(stack))