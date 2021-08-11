# 기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법입니다.
# 일반적인 상황에서 가장 많이 사용되는 정렬 알고리즘 중 하나입니다.
# 병합 정렬과 더불어 대부분의 프로그래밍 언어의 정렬 라이브러리의 근간이 되는 알고리즘입니다.
# 가장 기본적인 퀵 정렬은 첫 번째 데이터를 기준 데이터(Pivot)로 설정합니다.

def quicksort(array , start, end):
    if start == end:
        return 0
    pivot = start
    start = pivot + 1
    i, j = start, end

    print("i, j", i, j)
    while True:
        while array[i] < array[pivot] and i < j:
            i += 1
        while array[j] > array[pivot] and i < j:
            j -= 1
        if i > j:
            break
        # print("i, j", i, j)
        array[i], array[j] = array[j], array[i]

    # print("pivot", j)
    # if array[pivot] > array[j]:
    #     array[pivot], array[j] = array[j], array[pivot]
    #     quicksort(array, 0, j - 1)
    #     quicksort(array, (j + 1), end)
    # else:
    #     quicksort(array, (j + 1), end)
    print("test",array)
    
    

array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]
# array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(array)

quicksort(array, 0, len(array) - 1)
print(array)