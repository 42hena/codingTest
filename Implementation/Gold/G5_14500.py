N, M = map(int, input().split())
Map = []

for _ in range(N):
    Map.append(list(map(int, input().split())))
# print(Map)
maxVal = 0
for i in range(N):
    for j in range(M):
        #길쭉이
        if j + 3 < M: # 통과
            value = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i][j + 3]
            if maxVal < value:
                maxVal = value
        if i + 3 < N: # 통과
            value = Map[i][j] + Map[i + 1][j] + Map[i + 2][j] + Map[i + 3][j]
            if maxVal < value:
                maxVal = value

        # 정사각형
        if i + 1 < N and j + 1 < M: # 통과
            value = Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 1][j + 1]
            if maxVal < value:
                maxVal = value

        # 뾰족이
        #
        #
        ##
        if i + 2 < N and j + 1 < M:
            value = Map[i][j] + Map[i + 1][j] + Map[i + 2][j] + Map[i + 2][j + 1]
            if maxVal < value:
                maxVal = value
        ###
        #
        if i + 1 < N and j + 2 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i + 1][j]
            if maxVal < value:
                maxVal = value
        ##
         #
         #
        if i + 2 < N and j + 1 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 2][j + 1]
            if maxVal < value:
                maxVal = value
          #
        ###
        if i + 1 < N and j - 2 >= 0:
            value = Map[i][j] + Map[i + 1][j - 2] + Map[i + 1][j - 1] + Map[i + 1][j]
            if maxVal < value:
                maxVal = value
         #
         #
        ##
        if i + 2 < N and j - 1 >= 0:
            value = Map[i][j] + Map[i + 1][j] + Map[i + 2][j - 1] + Map[i + 2][j]
            if maxVal < value:
                maxVal = value
        
        ###
          #
        if i + 1 < N and j + 2 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i + 1][j + 2]
            if maxVal < value:
                maxVal = value
        ##
        #
        #
        if i + 2 < N and j + 1 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 2][j]
            if maxVal < value:
                maxVal = value
        #
        ###        
        if i + 1 < N and j + 2 < M:
            value = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 1][j + 2]
            if maxVal < value:
                maxVal = value
        
        #
        ##
         #
        if i + 2 < N and j + 1 < M:
            value = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j + 1]
            if maxVal < value:
                maxVal = value
         ##
        ##
        if i + 1 < N and j - 1 >= 0 and j + 1 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i + 1][j - 1] + Map[i + 1][j]
            if maxVal < value:
                maxVal = value
         #
        ##
        #
        if i + 2 < N and j - 1 >= 0:
            value = Map[i][j] + Map[i + 1][j - 1] + Map[i + 1][j] + Map[i + 2][j - 1]
            if maxVal < value:
                maxVal = value
        ##
         ##
        if i + 1 < N and j + 2 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 1][j + 2]
            if maxVal < value:
                maxVal = value

        ### 
         #
        if i + 1 < N and j + 2 < M:
            value = Map[i][j] + Map[i][j + 1] + Map[i][j + 2] + Map[i + 1][j + 1]
            if maxVal < value:
                maxVal = value
        #
        ##
        #
        if i + 2 < N and j + 1 < M:
            value = Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j]
            if maxVal < value:
                maxVal = value
         #
        ###
        if i + 1 < N and j - 1 >= 0 and j + 1 < M:
            value = Map[i][j] + Map[i + 1][j - 1] + Map[i + 1][j] + Map[i + 1][j + 1]
            if maxVal < value:
                maxVal = value
         #
        ##
         #
        if i + 2 < N and j - 1 >= 0:
            value = Map[i][j] + Map[i + 1][j - 1] + Map[i + 1][j] + Map[i + 2][j]
            if maxVal < value:
                maxVal = value
print(maxVal)