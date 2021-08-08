C = int(input())

for i in range(C):
    tmp = list(map(int, input().split()))
    N = tmp.pop(0)
    grade = tmp
    avg = sum(grade) / N
    cnt = 0
    for j in range(N):
        if grade[j] > avg:
            cnt += 1
    print("%.3f%%" %(round(cnt/N*100,3)))
    
    
