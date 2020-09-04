def solution(numbers, hand):
    answer = ''
    num_left = [1,4,7]
    num_right = [3,6,9]
    right = -1
    left = -1
    for i in numbers:
        if(i in num_left):
            answer+='L'
            left = i
        elif( i in num_right):
            answer+='R'
            right = i
        else:
            distL = dist(i,left)
            distR = dist(i,right)
            if (distL < distR):
                left = i
                answer+='L'
            elif(distL > distR):
                right = i 
                answer+='R'
            else:
                if(hand =="right"):
                    right = i 
                    answer+='R'
                else:
                    left = i
                    answer+='L'
    return answer
def dist(n , num):
    if(n == 2):
        if(num in [1,3]):
            return 1
        if(num in [4,6]):
            return 2
        if(num in [7,9]):
            return 3
    if(n == 5):
        if(num in [1,3]):
            return 2
        if(num in [4,6]):
            return 1
        if(num in [7,9]):
            return 2
    if(n == 8):
        if(num in [1,3]):
            return 3
        if(num in [4,6]):
            return 2
        if(num in [7,9]):
            return 1    
    if(n == 0):
        if(num in [1,3]):
            return 4
        if(num in [4,6]):
            return 3
        if(num in [7,9]):
            return 2    
    if(n==2):
        if num == 5:
            return 1
        elif num == 8:
            return 2
        elif num == 0:
            return 3
        elif num == -1:
            return 4
    if(n==5):
        if num == 2:
            return 1
        elif num == 8:
            return 1
        elif num == 0:
            return 2
        elif num == -1:
            return 3
    if(n==8):
        if num == 2:
            return 2
        elif num == 5:
            return 1
        elif num == 0:
            return 1
        elif num == -1:
            return 2
    if(n==0):
        if num == 2:
            return 3
        elif num == 5:
            return 2
        elif num == 8:
            return 1
        elif num == -1:
            return 1
    return 0