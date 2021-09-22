array1 = list(map(int, input()))
array2 = list(map(int, input()))
array3 = list(map(int, input()))
array4 = list(map(int, input()))

K = int(input())

for _ in range(K):
    num, direction = map(int, input().split())
    # 1번
    if num == 1:
        # 같다면
        if array1[2] == array2[6]:
            #우측
            if direction == 1:
                tmp = array1.pop()
                array1.insert(0, tmp)
            #좌측
            else:
                tmp = array1.pop(0)
                array1.insert(7, tmp)
        # 다르면
        else:
            #우측
            if direction == 1:
                tmp = array1.pop()
                array1.insert(0, tmp)
            #좌측
            else:
                tmp = array1.pop(0)
                array1.insert(7, tmp)

            # 2-3 같다면
            if array2[2] == array3[6]:
                #좌측
                if direction == 1:
                    tmp = array2.pop(0)
                    array2.insert(7, tmp)
                #우측
                else:
                    tmp = array2.pop()
                    array2.insert(0, tmp)
            # 2-3 다르면
            else:
                #좌측
                if direction == 1:
                    tmp = array2.pop(0)
                    array2.insert(7, tmp)
                #우측
                else:
                    tmp = array2.pop()
                    array2.insert(0, tmp)
                # 3-4 같다면
                if array3[2] == array4[6]:
                    #우측
                    if direction == 1:
                        tmp = array3.pop(0)
                        array3.insert(7, tmp)
                    #좌측
                    else:
                        tmp = array3.pop()
                        array3.insert(0, tmp)
                # 3-4 다르면
                else:
                    #우측
                    if direction == 1:
                        tmp = array3.pop(0)
                        array3.insert(7, tmp)
                        tmp = array4.pop()
                        array4.insert(0, tmp)
                    #좌측
                    else:
                        tmp = array3.pop()
                        array3.insert(0, tmp)
                        tmp = array4.pop(0)
                        array4.insert(7, tmp)
                        
        print(array1)
        print(array2)            

    if num == 2:
        # 왼쪽
        if array1[2] != array2[6]:
            if direction == 1:
                tmp = array1.pop(0)
                array1.insert(7, tmp)
            #좌측
            else:
                tmp = array1.pop()
                array1.insert(0, tmp)
        # 오른쪽
        if array2[2] == array3[6]:
            #우측
            if direction == 1:
                tmp = array2.pop()
                array2.insert(0, tmp)
                
            #좌측
            else:
                tmp = array2.pop(0)
                array2.insert(7, tmp)
        # 2-3 다르면
        else:
            #우측
            if direction == 1:
                tmp = array2.pop()
                array2.insert(0, tmp)
            #좌측
            else:
                tmp = array2.pop(0)
                array2.insert(7, tmp)
            # 3-4 같다면
            if array3[2] == array4[6]:
                #좌측
                if direction == 1:
                    tmp = array3.pop(0)
                    array3.insert(7, tmp)
                #우측
                else:
                    tmp = array3.pop()
                    array3.insert(0, tmp)
            # 3-4 다르면
            else:
                #좌측
                if direction == 1:
                    tmp = array3.pop(0)
                    array3.insert(7, tmp)
                    tmp = array4.pop()
                    array4.insert(0, tmp)
                #우측
                else:
                    tmp = array3.pop()
                    array3.insert(0, tmp)
                    tmp = array4.pop(0)
                    array4.insert(7, tmp)
        print(2)
    if num == 3:
        # 오른쪽
        if array3[2] != array4[6]:
            #좌측
            if direction == 1:
                tmp = array4.pop(0)
                array4.insert(7, tmp)
            #우측
            else:
                tmp = array4.pop()
                array4.insert(0, tmp)        
        # 왼쪽
        if array2[2] == array3[6]:
            #우측
            if direction == 1:
                tmp = array3.pop()
                array3.insert(0, tmp)
                
            #좌측
            else:
                tmp = array3.pop(0)
                array3.insert(7, tmp)
        # 2-3 다르면
        else:
            #우측
            if direction == 1:
                tmp = array3.pop()
                array3.insert(0, tmp)
            #좌측
            else:
                tmp = array3.pop(0)
                array3.insert(7, tmp)
            # 1-2 같다면
            if array1[2] == array2[6]:
                #좌측
                if direction == 1:
                    tmp = array2.pop(0)
                    array2.insert(7, tmp)
                #우측
                else:
                    tmp = array2.pop()
                    array2.insert(0, tmp)
            # 1-2 다르면
            else:
                #좌측
                if direction == 1:
                    tmp = array3.pop(0)
                    array3.insert(7, tmp)
                    tmp = array4.pop()
                    array4.insert(0, tmp)
                #우측
                else:
                    tmp = array3.pop()
                    array3.insert(0, tmp)
                    tmp = array4.pop(0)
                    array4.insert(7, tmp)        

        print(3)
    # if num == 4:
    #     print(4)