import heapq
N = int(input())

heap = []
for i in range(N):
    for j in list(map(int, input().split())):
        if len(heap) != N:
            heapq.heappush(heap, j)
        else:
            if j > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, j)
print(heap[0])