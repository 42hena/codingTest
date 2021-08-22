graph = []
command = []
for _ in range(5):
    graph.append(list(map(int,input().split())))
# print(graph)
for _ in range(5):
    command.append(list(map(int,input().split())))
cnt = 0
for items in command:
    for item in items:
        
        for row in range(5):
            for col in range(5):
                if graph[row][col] == item:
                    graph[row][col] = 'O'
                    break
        cnt += 1
        bingo = 0
        
        if graph[0][0] == 'O' and graph[1][1] == 'O' and graph[2][2] == 'O'  and graph[3][3] == 'O' and graph[4][4] == 'O':
            bingo += 1
            
        if graph[4][0] == 'O' and graph[3][1] == 'O' and graph[2][2] == 'O'  and graph[1][3] == 'O' and graph[0][4] == 'O':
            bingo += 1
            
        for i in range(5):
            if graph[0][i] == 'O' and graph[1][i] == 'O' and graph[2][i] == 'O'  and graph[3][i] == 'O' and graph[4][i] == 'O':
                bingo += 1
                
            if graph[i][0] == 'O' and graph[i][1] == 'O' and graph[i][2] == 'O'  and graph[i][3] == 'O' and graph[i][4] == 'O':
                bingo += 1
        if bingo >=3:
            print(cnt)
            exit()    