N = int(input())

me = list(map(int, input().split()))
owner = list(map(int, input().split()))

me.sort()
owner.sort()

# print(me)
# print(owner)

j = 0
for i in range(N):
    if me[j] < owner[i]:
        j += 1
if j >= (N + 1) // 2:
    print("YES")
else:
    print("NO")