#B2 1434 책 정리 success (greedy)
import sys
input = sys.stdin.readline

#N: box 갯수 M 책의 갯수
N, M = map(int, input().split())

#box, book정보
box_A = list(map(int, input().split()))     #box
book_B = list(map(int, input().split()))    #book

#낭비 값
waste_sum = 0

while len(book_B) != 0:
    if box_A[0] >= book_B[0]:
        box_A[0] -= book_B[0]
        if box_A[0] == 0:
            box_A.pop(0)
        book_B.pop(0)
    # 작다면 여기서 다 걸러짐
    else:
        waste_sum += box_A[0]
        box_A.pop(0)
    # print(waste_sum)

#남아 있는 박스는 다 더하면 됨
while len(box_A) != 0:
    waste_sum += box_A[0]
    box_A.pop(0)
print(waste_sum)