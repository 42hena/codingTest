#s5 14469 소가 길을 건너간 이유3
N = int(input())

cow_information = []

for i in range(N):
    cow_information.append(list(map(int, input().split())))
cow_information.sort(key=lambda x: x[0])
# print(cow_information)
time = 0
for i in range(N):
    if time == 0:
        time = cow_information[i][0] 
        time += cow_information[i][1] 
    else:
        if time < cow_information[i][0]:
            time = cow_information[i][0]
            time += cow_information[i][1]
        else:
            time += cow_information[i][1]
print(time)