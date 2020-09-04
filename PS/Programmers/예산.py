def solution(d, budget):
    answer = 0
    d = sorted(d)
    sum = 0
    for i in d:
        if (sum+ i)> budget:
            return answer
        sum+=i
        answer+=1
        if sum == budget:
            return answer
    return answer