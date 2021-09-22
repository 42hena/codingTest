import heapq
import sys

input = sys.stdin.readline
N = int(input())

leftheap = []
rightheap = []
for _ in range(N):
    value = int(input())
    if len(leftheap) == len(rightheap):
        heapq.heappush(leftheap, (-value, value))
    else:
        heapq.heappush(rightheap, (value, value))
    # print(leftheap)
    # print(rightheap)
    
    if rightheap and leftheap[0][1] > rightheap[0][1] :
        min = heapq.heappop(rightheap)[1]
        max = heapq.heappop(leftheap)[1]
        heapq.heappush(leftheap, (-min, min))
        heapq.heappush(rightheap, (max, max))
    print(leftheap[0][1])


# sorted_array = []
# for _ in range(N):
#     sorted_array.append(heapq.heappop(heap))
    
# for i in range(N):
#     print(sorted_array[i//2])