# 행복 왕국의 왕실 정원은 체스판과 같은 8 x 8 좌표 평면입니다.
# 왕실 정원의 특정한 한 칸에 나이트가 서 있습니다.
# 나이트는 매우 충성스러운 신하로서 매일 무술을 연마합니다.

# 나이트는 말을 타고 있기 때문에 이동을 할 때는 L자 형태로만 이동할 수 있으며 정원 밖으로는 나갈 수 없습니다.

# 나이트는 특정 위치에서 다음과 같은 2가지 경우로 이동할 수 있습니다.
# 1. 수평으로 두 칸 이동한 뒤에 수직으로 한 칸 이동하기
# 2. 수직으로 두 칸 이동한 뒤에 수평으로 한 칸 이동하기

#현재 나이트의 위치 입력받기
input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1

#나이트가 이동할 수 있는 8가지 방향 정의
steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

result = 0
for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]
    if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
        result += 1
print(result)

# 내 코드
# location = input()

# dx = [-1, -2, -2, -1, 1, 2, 2, 1]
# dy = [2, 1, -1, -2, -2, -1, 1, 2]

# x, y = int(location[1]), ord(location[0]) - ord('a') + 1

# cnt = 0 
# for i in range(8):
#     if x + dx[i] < 1 or x + dx[i] > 8  or y + dy[i] < 1 or y + dy[i] > 8:
#         continue
#     else:
#         cnt += 1
#     print(i,cnt)
# print(cnt)