str = input()
ans = int(str[0])
for i in range(1, len(str)):
    print(int(str[i]))
    if ans == 0:
        ans += int(str[i])
        continue
    if str[i] == '0' or str[i] == '1':
        ans += int(str[i])
    else:
        ans *= int(str[i])
print(ans)


    
    
    
