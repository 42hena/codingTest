d = [0] * 100
# 시간 복잡도는 O(N)
def fibo(x):
    print(f"f({str(x)})", end=" ")
    if x == 1 or x == 2:
        return 1
    if d[x] != 0:
        return d[x]
    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]
fibo(6)