def solution(n):
    temp = ['1','2','4']
    answer = ''
    while(n):
        n-=1
        answer+=str(temp[n%3])
        n=n//3
    answer = answer[::-1]
    return answer