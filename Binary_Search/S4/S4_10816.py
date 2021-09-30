from bisect import bisect_left, bisect_right

def count_value(array, value):
    # print(value)
    count = bisect_right(array, value) - bisect_left(array, value)
    # print(count)
    return count
    
N = int(input())
array = list(map(int, input().split()))
M = int(input())
values = list(map(int, input().split()))
array.sort()
for value in values:
    print(count_value(array, value), end=" ")


