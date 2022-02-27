n = int(input())
arrp = []
arrm = []
ans = 0
for i in range(n):
    num = int(input())
    if num > 1 :
        arrp.append(num)
    elif num <= 0:
        arrm.append(num)
    elif num == 1:
        ans += 1

arrp.sort(reverse=True)
arrm.sort()
size = len(arrp)
if size % 2 == 1:
    ans += arrp[-1]
    size -=1
for i in range(0, size, 2):
    ans += arrp[i] * arrp[i + 1]
size = len(arrm)
if size % 2 == 1:
    ans += arrm[-1]
    size -=1
for i in range(0, size, 2):
    ans += arrm[i] * arrm[i + 1]
print(ans)