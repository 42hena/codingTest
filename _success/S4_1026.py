N = int(input())

A = []
B = []

A = list(map(int,input().split()))
B = list(map(int,input().split()))
#print(A,B)
A.sort()
#print(A)
B.sort(reverse=True)
#print(B)
sum = 0
for i in range(len(A)):
    sum += A[i]*B[i]
print(sum)