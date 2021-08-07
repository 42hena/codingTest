T = int(input())

#입력
for i in range(T):
    N, M = map(int, input().split())
    printQ = list(map(int, input().split()))
    cnt = 1
    while len(printQ) != 0:
        if M == 0:
            # print("M == 0")
            if printQ[M] < max(printQ):
                tmp = printQ.pop(0)
                printQ.append(tmp)
                M = len(printQ) - 1
            else:
                print(cnt)
                break
            # print(printQ)
        else:
            # print("M != 0")
            if printQ[0]  == max(printQ):
                printQ.pop(0)
                M -= 1
                cnt += 1
            else:
                tmp = printQ.pop(0)
                printQ.append(tmp)
                M -= 1
            # print(printQ)