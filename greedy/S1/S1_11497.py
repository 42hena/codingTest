import sys
input = sys.stdin.readline

for _ in range(int(input())):

    N = int(input())
    array = list(map(int, input().split()))
    array.sort(reverse=True)

    front = []
    back = []

    while array:
        if array:
            front.append(array.pop())
        if array:
            back.append(array.pop())

    back.sort(reverse=True)
    array = front + back
    # print(array)
    dif = abs(array[0] - array[N - 1])
    for i in range(N - 1):
        if abs(array[i] - array[i + 1]) > dif:
            dif = abs(array[i] - array[i + 1])
    print(dif)
