#B1 14655 욱제는 도박쟁이야!! success (greedy)
import sys
input = sys.stdin.readline

# N값 입력 받기
N = int(input())

# 게임 정보 입력 받기
first_game = list(map(int, input().split()))
second_game = list(map(int, input().split()))
# print(first_game,second_game)

# 정답을 표시할 변수
get_point = 0

# 모든 점수 더하기
for i in range(N):
    get_point += abs(first_game[i]) + abs(second_game[i])
print(get_point)

# 느낌상 모든 것을 원하는 대로 할 수 있을 것 같다.