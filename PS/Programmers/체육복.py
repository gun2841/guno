def solution(n, lost, reserve):
    answer = 0
    arr = [1 for i in range(n+2)]
    
    for i in lost:
        arr[i]-=1

    for i in reserve:
        arr[i]+=1
        
    print(arr)

    for i in range(1,n+1):
        if( arr[i] == 1 or arr[i] ==2):
            answer+=1
        elif (arr[i] == 0):
            if(arr[i-1] == 2):
                arr[i-1]-=1
                arr[i]+=1
                answer+=1
            elif(arr[i+1]== 2):
                arr[i+1]-=1
                arr[i]+=1
                answer+=1
    

    return answer