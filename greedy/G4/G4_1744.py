N = int(input())
num = list(int(input()) for _ in range(N))
# print(num)
num.sort()

mindex = -1
pindex = -1

for i in range(N):
    if num[i] < 0:
        mindex = i
    elif num[i] > 0:
        pindex = i 
        break
# print(num)
if mindex!= -1:
    minus = num[0:mindex + 1]
else:
    minus = []
if pindex!= -1:
    plus = num[pindex:N]
else:
    plus = []
# print(minus, plus)
# print(len(minus), len(plus))
# print(mindex,pindex)
sum = 0
if len(minus) % 2 != 0:
    sum += minus.pop(mindex)
while len(minus) != 0:
    first = minus.pop(0)
    second = minus.pop(0)
    sum += first * second
# print("minussum",sum)

if len(plus) % 2 != 0 :
    sum += plus.pop(0)

while len(plus) != 0:
    first = plus.pop(0)
    second = plus.pop(0)
    sum += first * second
print(sum)

