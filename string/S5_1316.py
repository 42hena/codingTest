import sys
input = sys.stdin.readline

def check_group_word(str, size):
    countArray = [0] * 26
    for i, c in enumerate(str):
        # print(i, size)
        if i < size - 1:
            if countArray[ord(c) - ord('a')]:
                return False
            if not countArray[ord(c) - ord('a')] and str[i] != str[i + 1]:
                countArray[ord(c) - ord('a')] += 1
        else:
            if countArray[ord(c) - ord('a')]:
                return False

            
    return True
    

n = int(input())
ans = 0
for i in range(n):
    
    str = input().rstrip()
    size = len(str)
    if check_group_word(str, size):
        ans += 1
print(ans)