#s5 1439 뒤집기
S = input()

kind = []
cnt = 0
for i in range(len(S)):
    if len(kind) == 0:
        if S[i] == "0":
            kind.append("0")
        elif S[i] == "1":
            kind.append("1")
        cnt += 1
    else:
        if S[i] == "0" and kind[cnt - 1] == "1":
            kind.append("0")
            cnt += 1
        elif S[i] == "1" and kind[cnt - 1] == "0":
            kind.append("1")
            cnt += 1
print(len(kind)//2)