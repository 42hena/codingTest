B, C, D = map(int, input().split())

burger = list(map(int,input().split()))
side = list(map(int,input().split()))
beverage = list(map(int,input().split()))

sale_before = 0
sale_after = 0
burger.sort(reverse=True)
side.sort(reverse=True)
beverage.sort(reverse=True)

min = min(B, C, D)
for i in range(min):
    sale_before += (burger[i] + side[i] + beverage[i])
    sale_after += (burger[i] + side[i] + beverage[i]) * 0.9
for i in range(min, B):
    sale_before += burger[i]
    sale_after += burger[i]
for i in range(min, C):
    sale_before += side[i]
    sale_after += side[i]
for i in range(min, D):
    sale_before += beverage[i]
    sale_after += beverage[i]
print(sale_before)
print(round(sale_after))