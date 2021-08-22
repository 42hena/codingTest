init = input()
ans = input()

Min = len(init)
Max = len(ans)
while True:
    if init == ans:
        print(1)
        break
    if Max == Min:
        print(0)        
        break
    if ans[Max - 1] == 'A':
        ans = ans[:-1]
        Max -= 1
        
    else:
        ans = ans[:-1]
        ans = ans[::-1]
        Max -= 1