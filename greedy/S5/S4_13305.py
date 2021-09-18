#S4 13305 주유소

N = int(input())
load_len = list(map(int, input().split()))
oil_price = list(map(int, input().split()))

price_sum = 0
load_sum = 0
load_len.append(0)
oil_price[N - 1] = 0
print(load_len, oil_price)
i = 0
while i < N - 1:
    if oil_price[i] >= oil_price[i + 1]:
        price_sum += oil_price[i] * load_len[i]
        print("큰 경우", price_sum)
        i += 1
    else:
        load_sum = 0        # 0
        for j in range(i, N - 1):
            print(oil_price[i], oil_price[j])
            if i == N - 2:
                load_sum += load_len[j]
                break
            if oil_price[i] <= oil_price[j]:
                load_sum += load_len[j]
                load_len[j] = 0
            else:
                break
        print("load",load_sum)
        i = j
        price_sum += oil_price[i] * load_sum
    print("i = ", i)
# for i in range(N - 1):
#     if oil_price[i] >= oil_price[i + 1]:
#         price_sum += oil_price[i] * load_len[i]
#         print("큰 경우", price_sum)
#     else:
#         load_sum = load_len[i]
#         for j in range(i + 1, N - 1):
#             if oil_price[i] <= oil_price[j]:
#                 load_sum += load_len[j]
#                 load_len[j] = 0
#             else:
#                 break
#         # print("load",load_sum)
#         price_sum += oil_price[i] * load_sum
print(price_sum)