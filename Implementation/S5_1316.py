#fail
N = int(input())


arr = []
for i in range(N):
    arr.append(input())
print(arr)

sum = 0
for i in range(N):
    count = [0 for _ in range(26)]
    
    for j in range(len(arr[i])):
        if count[ord(arr[i][j]) - ord('a')] == 0:
            count[ord(arr[i][j]) - ord('a')] += 1
        else:
            break
        if j == len(arr[i]) - 1:
            sum += 1
print(sum)