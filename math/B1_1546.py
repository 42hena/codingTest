N = int(input())
arr = list(map(int, input().split()))
max_val = max(arr)
# print(test)
for i in range(N):
    arr[i] = arr[i]/max_val*100
# print(arr)
print(sum(arr)/N)
