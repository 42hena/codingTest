#fail
n, W = map(int, input().split())

day_information = []
for i in range(n):
    day_information.append(int(input()))

if n == 1:
    print(W)
    exit()

init_value = day_information[0]
if init_value > day_information[1]:
    coin = 0
else:
    coin = W // init_value
    W %= init_value

if n == 2:
    if init_value > day_information[1]:
        print(W)
    else:
        print(coin * day_information[1] + W)
    exit()
for i in range(1, n - 1):
    if day_information[i - 1] < day_information[i] and day_information[i] > day_information[i + 1]:
        W += coin * day_information[i]
        coin = 0
    elif day_information[i - 1] > day_information[i] and day_information[i] < day_information[i + 1]:
        coin = W // day_information[i]
        W %= day_information[i]
if coin != 0:
    W += day_information[i + 1] * coin
print(W)
