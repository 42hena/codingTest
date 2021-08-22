# S5_2693 N번째 큰 수
import sys

input = sys.stdin.readline

T = int(input())
# print(T)
for _ in range(T):
    array = list(map(int, input().split()))
    array.sort(reverse=True)
    print(array[2])