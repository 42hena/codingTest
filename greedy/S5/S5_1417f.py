#s5 1417
N = int(input())

arr = []

for i in range(N):
    arr.append(int(input()))
v = arr.pop(0)

arr.sort(reverse = True)
print(arr)
