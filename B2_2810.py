#B2 2810 컵홀더

N = int(input())

seat = input()

#처음 시작 1 S나오면 1 LL 나오면 1
count = 1 + seat.count('S') + seat.count('LL')
if N < count:
    print(N)
else: 
    print(count)
