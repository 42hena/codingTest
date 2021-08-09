#B2 14659 한조서열정리하고옴ㅋㅋ

N = int(input())

bow = list(map(int, input().split()))
maxVal = bow[0]
count = 0
max = 0 
for i in range(1, N):
    if maxVal < bow[i]:
        if max < count:
            max = count
        maxVal = bow[i]
        count = 0
    else:
        count += 1
if max < count:
    max = count
print(max)

# 시간 초과
#print(bow)
# max = 0
# for i in range(N):
#     count = 0
#     for j in range(i + 1, N):
#         if bow[i] > bow[j]:
#             count += 1
#         else:
#             break
#     if max < count:
#         max = count
# print(max)