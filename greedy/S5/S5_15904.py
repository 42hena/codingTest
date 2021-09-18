#s5 15904

name = input()

charset = ["U","C","P","C"]
cnt = 0
for i in range(len(name)):
    if cnt == 4:
        break
    if name[i] == charset[cnt]:
        cnt += 1
if cnt == 4:
    print("I love UCPC")
else:
    print("I hate UCPC")
