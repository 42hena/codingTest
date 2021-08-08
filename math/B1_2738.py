N, M = map(int, input().split())
A = []
for i in range(N):
    A.append(list(map(int, input().split())))
B = []
for i in range(N):
    B.append(list(map(int, input().split())))

C = []
for i in range(N):
    C.append([])
    for j in range(M):
        C[i].append(A[i][j] + B[i][j])
# print(C)

for i in range(N):
    for j in range(M):
        print(C[i][j], end=" ")
    print()