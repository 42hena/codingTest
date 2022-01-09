answer = ""

def find_ans(w):
    #1 빈경우 빈 문자열 반환
    if len(w) == 0:
        return ""
    
    #2 분리 작업
    cnt1 = 0
    cnt2 = 0
    index = 0
    for i in w:
        if i == '(':
            cnt1 += 1
        else:
            cnt2 += 1
        if cnt1 == cnt2:
            break
        index += 1
    
    u = w[0:index + 1]
    v = w[index + 1 :]
    print("sep",u, v)
    
    #3 u 올바른지 확인
    flag = True
    stack = []
    for i in u:
        if i == '(':
            stack.append(i)
        else:
            if len(stack):
                stack.pop()
            else:
                flag = False
                break
    if len(stack) > 0:
        flag = False
    # 3-1
    if flag:
        print("3-1")
        u += find_ans(v)
        return u
    else:
        #4 u가올바르지 않음
        tmp = ""
        #4-1 빈 문자열에 첫번째 문자 (넣음
        tmp += "("
        print("4-1")
        tmp += find_ans(v)
        tmp += ")"

        if len(u) > 2:
            tmpu = u[1:-1]
            tmpa = ""
            for i in range(len(tmpu)):
                if tmpu[i] == '(':
                    tmpa += ")"
                else:
                    tmpa += "("
            tmp += tmpa
        else:
            tmp += ""
        print(tmp)
        return tmp
    
def solution(p):
    answer = find_ans(p)
    return answer