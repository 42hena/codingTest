array = []
for _ in range(10):
    array.append(int(input())%42)
# print(array)
array.sort()
cnt = 0
for i in range(10):
    if array[i] == -1:
        continue
    tmp = array[i]
    cnt += 1
    for j in range(i + 1, 10):
        if tmp == array[j]:
            array[j] = -1
        else:
            break
print(cnt)