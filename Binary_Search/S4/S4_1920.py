N = int(input())
array = list(map(int, input().split()))
M = int(input())
search = list(map(int, input().split()))

array.sort()

def search_value(x):
    start = 0
    end = N - 1
    while start <= end:
        mid = (start + end) // 2
        if array[mid] > x:
            end = mid - 1
        elif array[mid] < x:
            start = mid + 1
        else:
            return True
    return False
for i in search:
    if search_value(i):
        print(1)
    else:
        print(0)