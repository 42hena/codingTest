# G5 2812 크게 만들기
N, K = map(int, input().split())
val = input()
arr = []
for i in range(len(val)):
    arr.append(val[i])

print(arr)

count = 0
while True:
    print("i =", i)
    print(arr)

    while True:
        if count >= K:
            break
        if (i > len(arr) - 1):
            break

        if i != len(arr) - 1:
            if (arr[i] < arr[i + 1]):
                del arr[i]
                i -= 1
                count += 1
                print(arr)
            else:
                break
        else:
            print("출력")
            break


for i in range(len(arr) - 1):

    if count >= K:
        break

    while True:
        if count >= K:
            break
        if (i > len(arr) - 1):
            break

        if i != len(arr) - 1:
            if (arr[i] < arr[i + 1]):
                del arr[i]
                i -= 1
                count += 1
                print(arr)
            else:
                break
        else:
            print("출력")
            break


# i = 0
# while i < len(arr):
#     print("len:", len(arr))
#     while int(arr[i]) < int(arr[i + 1]):
#         arr.pop(i)
#     print(arr)
#     i += 1
