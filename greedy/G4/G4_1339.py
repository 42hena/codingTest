#G4 1339 단어 수학

N = int(input())

value = [0 for _ in range(26)]
cnt = [0 for _ in range(26)]
text = []
for i in range(N):
    Alpha = input()
    text.append(Alpha)

for i in range(N):
    for j in range(len(text[i])):
        value[ord(text[i][j]) -ord('A')] += pow(10, len(text[i]) - j - 1)

char_value = 9
for i in range(10):
    max = 0
    max_index = -1
    for j in range(26):
        if max < value[j]:
            max_index = j
            max = value[j]
    value[max_index] = 0
    if max_index != -1:
        cnt[max_index] = char_value
        char_value -= 1
# print(text)
# print(cnt)

#대입
sum = 0
for i in range(N):
    for j in range(len(text[i])):
        sum += cnt[ord(text[i][j]) - ord('A')] * pow(10, len(text[i]) - 1 - j)
print(sum)