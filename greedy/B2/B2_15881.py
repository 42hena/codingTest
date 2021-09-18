#B2 15881 Pen Pineapple Apple Pen success (greedy)
import sys
input = sys.stdin.readline

# 입력
n = int(input())
string = input()

#정답을 나타낼 변수
pPAp_cnt = 0

i = 0
while i < n - 3:
    #pPAp가 모여야 한개다(index 4개 증가)
    if string[i] == 'p' \
        and string[i + 1] == 'P' \
        and string[i + 2] == 'A' \
        and string[i + 3] == 'p':
        pPAp_cnt += 1
        i += 4
    #아닐 경우 index 1칸 증가
    else:
        i += 1

#정답 출력
print(pPAp_cnt)