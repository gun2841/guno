def solution(arr):
    answer = []
    pivot = arr[0]
    answer.append(pivot)
    for i in range(1,len(arr)):
        if(pivot!=arr[i]):
            pivot = arr[i]
            answer.append(pivot)
    return answer