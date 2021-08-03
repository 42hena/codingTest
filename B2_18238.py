#ZOAC

Str = input()
Alpha = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
currentChar = 0
Sum = 0
for i in range(len(Str)):
    for j in range(1, 14):
        print(Alpha[ (currentChar + j) % 26], Alpha[ (currentChar - j) % 26])
        if Alpha[ (currentChar + j) % 26] == Str[i]:
            currentChar = (currentChar + j) % 26
            Sum += j
            break
        elif Alpha[ (currentChar - j) % 26] == Str[i]:
            currentChar = (currentChar - j) % 26
            Sum += j
            break
print(Sum)