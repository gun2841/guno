def solution(answers):
    answer = []
    a = [1,2,3,4,5]
    b = [2,1,2,3,2,4,2,5]
    c = [3,3,1,1,2,2,4,4,5,5]
    arr = [0,0,0]

    for i in range(len(answers)):
        if answers[i] == a[(i%5)]:
            arr[0]+=1
        if answers[i] == b[(i%8)]:
            arr[1]+=1
        if answers[i] == c[(i%10)]:
            arr[2]+=1

    max =0
    if arr[0]>max:
        max = arr[0]
    if arr[1] > max:
        max = arr[1]
    if arr[2] >max:
        max = arr[2]
    if arr[0] == max:
        answer.append(1)
    if arr[1] ==max:
        answer.append(2)
    if arr[2] == max:
        answer.append(3)
    return answer