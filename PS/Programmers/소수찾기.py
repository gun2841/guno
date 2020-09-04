def solution(n):
    answer = 0
    n+=1
    arr = [True] *(n)
    m = int(n**0.5)
    arr[0] = False
    arr[1] = False
    for i in range(2,m+1):
        if arr[i] == True:
            for j in range(i+i,n,i):
                arr[j] = False

    for i in arr:
        if i == True:
            answer+=1

    return answer