#B3 11034
import sys

lines = sys.stdin.readlines()
for line in lines:
    A, B, C = map(int,line.split())
    if B - A < C - B:
        print(C - B - 1)
    else:
        print(B - A - 1)
