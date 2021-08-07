text = input()

cnt = 0
i = 0
while i < len(text):
    if text[i] == 'c' and len(text) - i > 1:
        if text[i + 1] == '=' or text[i + 1] == '-':
            cnt += 1
            i += 2
            continue
    elif text[i] == 'd' and len(text) - i > 1:
        if text[i + 1] == '-':
            cnt += 1
            i += 2
            continue
        elif text[i + 1] == 'z' and len(text) - i > 2:
            if text[i + 2] == '=':
                cnt += 1
                i += 3
                continue
    elif text[i] == 'l' and len(text) - i > 1:    
        if text[i + 1] == 'j':
            cnt += 1
            i += 2
            continue
    elif text[i] == 'n' and len(text) - i > 1:
        if text[i + 1] == 'j':
            cnt += 1
            i += 2
            continue
    elif text[i] == 's' and len(text) - i > 1:
        if text[i + 1] == '=':
            cnt += 1
            i += 2
            continue
    elif text[i] == 'z' and len(text) - i > 1:
        if text[i + 1] == '=':
            cnt += 1
            i += 2
            continue
    cnt += 1
    i += 1
    # print(cnt)
print(cnt)