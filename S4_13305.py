#S4 13305 주유소

N = int(input())
load_len = list(map(int, input().split()))
oil_price = list(map(int, input().split()))
# print(load_len, oil_price)
price_sum = 0
load_sum = 0
for i in range(N - 1):
    if oil_price[i] > oil_price[i + 1]:
        price_sum += oil_price[i] * load_len[i]
    else:
        
        load_sum = load_len[i]
        for j in range(i + 1, N - 1):
            if oil_price[i] <= oil_price[j]:
                load_sum += load_len[j]
                load_len[j] =0
            else:
                break
        # print("load",load_sum)
        price_sum += oil_price[i] * load_sum
print(price_sum)