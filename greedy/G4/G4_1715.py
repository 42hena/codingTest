#g4 1715
import heapq

N = int(input())
arr = list(int(input()) for _ in range(N))
heapq.heapify(arr)

print(arr)

sum = 0
while len(arr) != 1:
    first = heapq.heappop(arr)
    second = heapq.heappop(arr)
    sum += first + second
    heapq.heappush(arr, first + second)
print(arr)
print(sum)
#시간 초과
# arr = []
# for i in range(N):
#     arr.append(int(input()))
# if N == 1:
#     print(*arr)
#     exit()

# arr.sort()
# sum = 0
# for i in range(N - 1):
#     sec = arr.pop(1)
#     fir = arr.pop(0)
#     value = fir + sec
#     sum += value
    
#     if len(arr) == 0:
#         arr.append(value)
#         break
#     for j in range(len(arr)):
#         if value < arr[j] :
#             arr.insert(j, value)
#         elif j == len(arr) - 1:
#             arr.insert(j, value)
    
# print(sum)
