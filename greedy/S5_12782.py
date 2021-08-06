T = int(input())

for i in range(T):
    first, second = map(str, input().split())
    first_1 = 0
    second_1 = 0
    same_cnt = 0
    for j in range(len(first)):
        if first[j] == second[j]:
            same_cnt += 1
        else:
            if first[j] == '1':
                first_1 += 1
            if second[j] == '1':
                second_1 += 1
    print(abs(first_1 - second_1) + (len(first) - same_cnt - abs(first_1 - second_1))//2)
