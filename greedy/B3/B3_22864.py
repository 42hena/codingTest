#B3 22864 피로도 success? (greedy)
import sys
input = sys.stdin.readline

#A: 피로도 증가율 B: 일 증가율 C: 피로도 감소율 M:최대 피로도
A, B, C, M = map(int, input().split())
# print(A, B, C, M)

# 피로도 증가 > 최대 피로도
if A > M:
    print(0)
    exit()

#일 합, 피로도
work_sum = 0
fatigue = 0

#24시간 동안 최적의 값을 구하기
for _ in range(24):
    # 현재 피로도 + 피로도 증가 < 최대피로도
    if fatigue + A < M:
        fatigue += A
        work_sum += B
    # 현재 피로도 + 피로도 증가 >= 최대피로도
    else:
        fatigue -= C
print(work_sum)