# for _ in range(int(input())):
for i in range(1, 73):
    # H, W, N = map(int, input().split())
    H = 6
    W = 12
    N = i
    if N%H == 0:
        if N//H < 10:
            print("%d0%d" %(H, N//H))
        else:
            print("%d%d" %(N%H, N//H))
        
    else:
        if N//H < 10:
            print("%d0%d" %(N%H, N//H+1))
        else:
            print("%d%d" %(N%H, N//H+1))