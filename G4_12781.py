#G4 12781 PIZZA ALVOLOC

a1, b1, a2, b2, a3, b3, a4, b4 = map(int,input().split())

val1 = (a1*b2+a2*b3+a3*b1) - (b1*a2+b2*a3+b3*a1)
val2 = (a1*b2+a2*b4+a4*b1) - (b1*a2+b2*a4+b4*a1)

#print(val1, val2)
if (val1 * val2 < 0):
    print(1)
else:
    print(0)
# x1 = (b2 - b1)/(a2 - a1)
# y1 = b1 - x1 * a1
# x2 = (b4 - b3) / (a4 - a3)
# y2 = b3 -x2 * a3
# x = (y2 - y1) / (x1 - x2)
# y = x1 * x - y1

# maxX = max(a1,a2)
# maxY = max(b1,b2)
# minX = min(a1,a2)
# minY = min(b1,b2)
# if ( x > minX and x < maxX and y > minY and y < maxY):
#     print(1)
# else:
#     print(0)

