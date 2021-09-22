A, B = map(str, input().split())

count = 1

while True:
    if int(B) < int(A):
        count = -1
        break
    if B == A:
        break
    if int(B) % 2 == 0:
        B = str(int(B) // 2)
    elif B[len(B) - 1] == '1':
        B = B[:-1]
    # print(B, type(B))
    else:
        count = -1
        break
    count += 1
print(count)