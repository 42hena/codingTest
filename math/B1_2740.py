#행렬 곱셈 나중에 중요할듯

N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(list(map(int, input().split())))

M, K = map(int, input().split())
for i in range(M):
    B.append(list(map(int, input().split())))
# print(A)
# print(B)
C = []
for i in range(N):
    C.append([])
    for j in range(K):
        sum = 0
        # print("ij-",i,j)
        for k in range(M):
            sum += A[i][k] * B[k][j]
        C[i].append(sum)

for i in range(N):
    for j in range(K):
        print(C[i][j], end=" ")
    print()