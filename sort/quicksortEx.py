# 기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법입니다.
# 일반적인 상황에서 가장 많이 사용되는 정렬 알고리즘 중 하나입니다.
# 병합 정렬과 더불어 대부분의 프로그래밍 언어의 정렬 라이브러리의 근간이 되는 알고리즘입니다.
# 가장 기본적인 퀵 정렬은 첫 번째 데이터를 기준 데이터(Pivot)로 설정합니다.

def quicksort(array , start, end):
    print("s")
    if start >= end:
        return
    pivot = start
    i = start + 1
    j = end

    while i <= j:
        while i <= end and array[i] <= array[pivot]:
            i += 1
        while start < j and array[j] >= array[pivot]:
            j -= 1
        
        if i > j:
            array[j], array[pivot] = array[pivot], array[j]
        else:
            array[i], array[j] = array[j], array[i]
        # print("i, j", i, j)
    quicksort(array, start, j - 1)
    quicksort(array, (j + 1), end)    
    
    

array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]
# array = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]


quicksort(array, 0, len(array) - 1)
print(array)