def recursive(string, index, L, C, arr):
    if len(arr) == L:
        cnt1 = 0
        cnt2 = 0
        for i in range(L):
            if arr[i] in ['a','e','i','o','u']:
                # print("val", arr[i])
                cnt1 += 1
        cnt2 = L - cnt1
        if cnt1 >= 1 and cnt2 >=2:
            for i in range(L):
                print(arr[i], end="")
            print()
        # print("return after")
        return
    for i in range(index, C):
        # print(arr)
        arr.append(string[i])
        recursive(string, i + 1, L, C, arr)
        # print(i, arr)
        arr.pop()

L, C = map(int, input().split())

string = list(input().split())

string.sort()
# print(string)
arr = []

recursive(string, 0, L, C, arr)