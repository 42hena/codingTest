import sys

lines = sys.stdin.readlines()
for line in lines:
    S = list(map(int, line.split()))
    n = S[0]
    del S[0]
    print(S)

    # for a in range(n):
    #     for b in range(a + 1, n):
    #         for c in range(b + 1, n):
    #             for d in range(c + 1, n):
    #                 for e in range(d + 1, n):
    #                     for f in range(e + 1, n):
    #                         print(S[a],S[b],S[c],S[d],S[e],S[f])