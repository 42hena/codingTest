import sys

def all_function(S):
    S = [i for i in range(1, 21)]
    return S
    
def add_function(S, num):
    if S.count(int(num)) == 0:
        S.append(int(num))
    return S

def remove_function(S, num):
    if S.count(int(num)) > 0:
        S.remove(int(num))
    return S

def check_function(S, num):
    if S.count(int(num)) > 0:
        print(1)
    else:
        print(0)

def toggle_function(S, num):
    if S.count(int(num)) > 0:
        S = remove_function(S, num)
    else:
        S = add_function(S, num)
    return S

M = int(sys.stdin.readline())

S = []

for i in range(M):
    command = sys.stdin.readline()
    command = command.split()
    if command[0] == "all":
        S = all_function(S)
        # print(S)
    elif command[0] == "empty":
        S = []
        # print(S)
    # elif command[0] == "print":
    #     print(S)
    else:
        num = command[1]
        if command[0] =="add":
            S = add_function(S, num)
        elif command[0] =="remove":
            S = remove_function(S, num)
        elif command[0] =="check":
            check_function(S, num)
        elif command[0] =="toggle":
            S = toggle_function(S, num)
