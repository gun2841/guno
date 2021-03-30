def solution(a, b):
    answer = 0
    if(a>b):
        a,b=b,a
    answer = (b+1)*b//2 -(a-1)*a//2
    return answer