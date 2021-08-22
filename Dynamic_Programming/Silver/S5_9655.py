N = int(input())

cnt_of_one = N % 3
cnt_of_three = N // 3

if (cnt_of_one + cnt_of_three) % 2 == 0:
    print("CY")
else:
    print("SK")