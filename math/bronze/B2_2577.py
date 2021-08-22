A = int(input())
B = int(input())
C = int(input())

value = A * B * C
# print(value)

count = [0] * 10
while value:
    count[value%10] += 1
    value //= 10

for cnt in count:
    print(cnt)