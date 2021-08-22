def lower_than_hundred(N):
    return N
    
def upper_than_hundred(N):
    cnt = 0
    for num in range(100, N + 1):
        if num // 100 - num %100 //10 == num%100//10- num%10:
            # print(num)
            cnt += 1
    return cnt + 99
    
N = int(input())
if N<100:
    print(lower_than_hundred(N))
else:
    print(upper_than_hundred(N))