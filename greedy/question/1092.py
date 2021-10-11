from collections import deque
import sys
# import time
input = sys.stdin.readline
N = int(input())
crains = list(map(int, input().split()))
crains.sort(reverse=True)
M = int(input())
boxes = list(map(int, input().split()))
boxes.sort(reverse=True)
boxes = deque[boxes]
# start = time.time()

def ispossible(A, B):
    if A < B:
        return False
    return True

if not ispossible(crains[0], boxes[0]):
    print(-1)
    exit(0)
# print(crains, boxes)
times = 0
temp = []
while boxes or temp:
    temp.clear()
    times += 1
    i = 0
    while i < len(crains):
        if boxes:
            value = boxes.pop()
            if crains[i] < value:
                temp.append(value)
            else:
                i += 1
        else:
            break
    while temp:
        boxes.append(temp.pop())
print(times)
# print(time.time() - start)