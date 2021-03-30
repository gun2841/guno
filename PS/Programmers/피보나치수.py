def solution(n):
    answer = 0
    a = 0
    b = 1
    for i in range(n):
        a ,b = b, a+b
    
    return a%1234567