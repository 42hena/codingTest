from bisect import bisect_left, bisect_right

x = int(input())
array = list(map(int, input().split()))
print(bisect_right(array, x) - bisect_left(array, x))

