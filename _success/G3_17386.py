#G3 17386 선분 교차1
#실패
x1, y1, x2, y2 = map(int,input().split())
x3, y3, x4, y4 = map(int,input().split())

val1 = (x1*y2+x2*y3+x3*y1) - (y1*x2+y2*x3+y3*x1)
val2 = (x1*y2+x2*y4+x4*y1) - (y1*x2+y2*x4+y4*x1)

val3 = (x3*y4+x4*y1+x1*y3) - (y3*x4+y4*x1+y1*x3)
val4 = (x3*y4+x4*y2+x2*y3) - (y3*x4+y4*x2+y2*x3)

#print(val1, val2)
if (val1 * val2 < 0 and val4 * val4 < 0):
    print(1)
else:
    print(0)
