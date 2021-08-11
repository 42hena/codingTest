
n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort(reverse=True)

# 첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 K번 비교
for i in range(k):
    # A의 원소가 B의 원소보다 작은 경우
    if i < k:
        # 두 원소를 교체
        a[i], b[i] = b[i], a[i]
    else:
        break
print(sum(a))

# 내 코드
# N, K = map(int, input().split())
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))

# print(A, B)
# A.sort()
# B.sort(reverse=True)

# ans = 0
# for i in range(len(A)):
#     if i < K:
#         ans += B[i]
#     else:
#         ans += A[i]
# print(ans)