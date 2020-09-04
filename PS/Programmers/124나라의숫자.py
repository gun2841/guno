def solution(n):
    answer = ''
    while(n):
        answer+=str(n%3)
        n=n//3
    return answer[::-1]

s = int(input())
print(solution(s))