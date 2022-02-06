#[2019 카카오 개발 겨울 인턴십]
#브루트 포스 문제
s = set()
tmp = []
visited = [False] * 8
def compareid(userStr, banStr):
    if len(userStr) == len(banStr):
        for i in range(len(userStr)):
            if banStr[i] == '*':
                continue
            if banStr[i] == userStr[i]:
                continue
            else:
                return False
        
        return True
    else:
        return False
    
def getvalue(user_id, banned_id, userSize, banSize, index):
    if index == banSize:
        # adds = ""
        test = sorted(tmp)
        # tmp.sort()
        adds = "".join(test)
        s.add(adds)
        # print(adds)
        
        return 

    for i in range(userSize):
        if not visited[i] and compareid(user_id[i], banned_id[index]):
            visited[i] = True
            tmp.append(str(i))
            getvalue(user_id, banned_id, userSize, banSize, index + 1)
            tmp.pop()
            visited[i] = False
        

def solution(user_id, banned_id):
    
    answer = 0
    userSize = len(user_id)
    banSize = len(banned_id)
    getvalue(user_id, banned_id, userSize, banSize, 0)
    answer = len(s)
    return answer