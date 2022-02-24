def solution(msg):
    
    diction = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9, 'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15, 'P': 16, 'Q': 17, 'R': 18, 'S': 19, 'T': 20, 'U': 21, 'V': 22, 'W': 23, 'X': 24, 'Y': 25, 'Z': 26}
    cnt = 27
    answer = []
    i = 0
    size = len(msg)
    tmp = ""
    flag = False
    while i < size:
        tmp = ""
        j = i
        while (j < size):
            tmp += msg[j]
            # print("tmp",tmp)
            if diction.get(tmp) == None:
                diction[tmp] = cnt
                cnt+=1;
                a = tmp[:j - i]
                # print("ans", a)
                answer.append(diction[a])
                i += (j - i - 1)
                break
            else:
                j += 1
                if j == size:
                    flag = True
                    break
        if flag:
            break
        i+=1
    if tmp != "":
        answer.append(diction[tmp])
    return answer