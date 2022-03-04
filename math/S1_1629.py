a, b, c = map(int, input().split())

itotal = 0
total = 1
i = 1
value = a
while itotal != b:
    if (i & b) == i:
        total *= value
        total %= c
        itotal += i
    value = pow(value, 2) % c
    i *= 2
print(total)