n = int(input())
data = list(map(int, input().split()))

data.sort()

result = 0
count = 0

for i in data:
    count += 1
    if count >= i:
        result += 1
        count = 0
print(result)

# N = int(input())
# arr = list(map(int, input().split()))
# print(arr)
# arr.sort()
# print(arr)

# result = 0
# for i in range(N):
#     cnt = 0
#     for j in range(i, N):
#         if arr[i] == arr[j] and j - i < arr[i]:
#             cnt += 1
#         else:
#             break
#     if arr[i] == cnt:
#         result += 1
# print(result)

