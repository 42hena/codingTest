from collections import deque

A, B = map(str, input().split())


def BFS():
    queue = deque([A])
    count = 1 
    while queue:
               
        for _ in range(len(queue)):
            value = queue.popleft()
            # print(value, type(value))
            if int(value) > int(B):
                continue
            elif value == B:
                return count
            queue.append( str(int(value) * 2) )
            queue.append( value + '1')
        # print(queue)
        count += 1
ans = BFS()
if not ans:
    print(-1)
else:
    print(ans)