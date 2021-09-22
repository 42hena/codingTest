from collections import deque
N = int(input())
mapp = list(map(int, input().split()))
start, end = map(int, input().split())
mapp.insert(0, 0)

queue = deque( [(start, mapp[start])])
cnt = 0
while queue:
    cnt +=1
    # print(cnt, queue)
    for _ in range(len(queue)):
        index, jump = queue.popleft()
        # print(index, jump)
        if (end - index) % jump == 0:
            print(cnt)
            exit()
        i = 1
        while index + jump*i <= end:
            queue.append((index + jump*i, mapp[index + jump*i]))
            # queue.append((index - jump*i, mapp[index - jump*i]))
            i += 1
        i = 1
        while index - jump*i >= end:
            queue.append((index - jump*i, mapp[index - jump*i]))
            # queue.append((index - jump*i, mapp[index - jump*i]))
            i += 1
print(-1)
    