N = int(input())

cnt_of_one = N % 4
cnt_of_four = N // 4

if (cnt_of_one + cnt_of_four) % 2 == 0:
    print("CY")
else:
    print("SK")