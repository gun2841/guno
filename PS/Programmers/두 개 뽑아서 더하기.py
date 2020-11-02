def solution(numbers):
    n = len(numbers)
    answer = { }
    answer = set()
    for i in range(n):
        for j in range(i+1,n):
            answer.add(numbers[i] + numbers[j])
    ans = list(answer)
    ans.sort()
    return ans