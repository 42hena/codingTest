N = int(input())
A, B, C, D, E, F = map(int, input().split())

case3 = [[A, B, C], [A, B, D], [A, C, E], [A, D, E], [B, D, F], [B, C, F], [C, E, F],[D, E, F],]
case2 = [[A, B], [A, C], [A, D], [A, E], [B, C], [B, D], [C, E], [D, E],
            [B, F], [C, F], [D, F], [E, F]]

Min = 151
Min_index = -1

for index, value in enumerate(case3):
    if Min > sum(value):
        Min = sum(value)
        Min_index = index
# print(Min_index, Min)
A3 = min(case3[Min_index])
C3 = max(case3[Min_index])
B3 = Min - A3 - C3


Min_value = min(A, B, C, D, E, F)

Min = 101
Min_index = -1
for index, value in enumerate(case2):
    if Min > sum(value):
        Min = sum(value)
        Min_index = index
A2 = min(case2[Min_index])
B2 = max(case2[Min_index])


# print(A, B, C)

if N == 1:
    print(A + B + C+ D+ E+ F- max(A, B, C, D, E, F))
elif N == 2:
    print((A3 + B3 + C3) * 4 + (A2 + B2) *  4)
else:
    print((A3 + B3 + C3) * 4 + (A2 + B2) *  4 + (Min_value) * (N - 2) * (N - 2) * 5 + (A2 + B2) * (N - 2) * 8 + Min_value*(N - 2)* 4)
# case 1: 21 - 6
# case 2: (A + B + C) * 4 + (A + B) *  4
# case 3: (A + B + C) * 4 + (A + B) *  4 + (A)1 * 1 * 5 + (A + B) * 8 + A*4
# case 4: (A + B + C) * 4 + (A + B) *  4 + (A)2 * 2 * 5 + (A + B) * 2 * 8 + A*2*4

# case 5: (A + B + C) * 4 + (A + B) *  4 + (A)3 * 3 * 5 + (A + B) * 3 * 8 + A*3*4


