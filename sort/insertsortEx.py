# 처리되지 않은 데이터를 하나씩 골라 적절한 위치에 삽입합니다.
# 선택 정렬에 비해 구현 난이도가 높은 편이지만, 일반적으로 더 효율적으로 동작합니다.

# 삽입 정렬의 시간 복잡도는 O(N^2)이며, 선택 정렬과 마찬가지로 반복문이 두 번 중첩되어 사용됩니다.
# 삽입 정렬은 현재 리스트의 데이터가 거의 정렬되어 있는 상태라면 매우 빠르게 동작합니다.
# 최선의 경우 O(N)의 시간 복잡도를 가집니다.
# 이미 정렬되어 있는 상태에서 다시 삽입 정렬을 수행하면 어떻게 될까요

for i in range(10, 0, -1):
    print(i)

#정석
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]
for i in range(1, len(array)):
    for j in range(i, 0, -1):
        if array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
        else:
            break    
    print(array)


# 내 코드
# array = list(map(int, input().split()))
# for i in range(1, len(array)):
#     for j in range(i + 1):
#         if array[j] > array[i]:
#             break
#     print(i, j)
#     tmp = array.pop(i)
#     print("뺀값", tmp)
#     array.insert(j, tmp)
#     print(array)