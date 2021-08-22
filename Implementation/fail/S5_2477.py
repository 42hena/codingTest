K = int(input())
array = []
for i in range(6):
    array.append(list(map(int, input().split())))
print(array)
if array[0][1] > array[2][1] and array[1][1] > array[3][1]:
    big = array[0][1] *  array[1][1]
    small = array[3][1] *  array[4][1]
    print(big, small)
    print((big - small) * K)
else:
    small = array[2][1] *  array[1][1]
    big = array[5][1] *  array[4][1]
    print(big, small)
    print((big - small) * K)