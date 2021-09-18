#s5 9237

N = int(input())
time = list(map(int, input().split()))
time.sort(reverse=True)
for i in range(N):
    time[i] += i + 1
print(max(time) + 1)
