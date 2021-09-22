import itertools

L, C = map(int, input().split())
array = list(input().split())
array.sort()
# print(array)
it = itertools.combinations(array, L)
for item in it:
    for i in item:
        print(i, end="")
    print()