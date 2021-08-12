import sys
input = sys.stdin.readline
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
print(a)
count = 0
for i in range(n):
    if max(a) == a[n-1]:
        print(count)
        break
    else:
        count += 1

