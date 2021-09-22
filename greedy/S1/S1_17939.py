from collections import deque
N = int(input())

array = deque(list(map(int, input().split())))
Maxval = max(array)
money = 0
coin = 0

while array:
    value = array.popleft()
    if value < Maxval:
        coin += 1
        money -= value
    else:
        money += value * coin
        coin = 0
        if array:
            Maxval = max(array)
    # print(coin, money)
print(money)