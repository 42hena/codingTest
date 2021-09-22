import sys
input = sys.stdin.readline

for _ in range(int(input())):
    array = []
    
    value = int(input())

    while value:
        a, b = 0, 1
        while b <= value:
            a, b = b, a + b
            # print(a, b)
        array.append(a)
        value -= a
    while array:
        print(array.pop(), end=" ")
    print()
