def solution(n, m):
    answer = []
    g = gcd(n,m)
    answer.append(g)
    answer.append(int(n*m/g))
    return answer
def gcd(a,b):
    if a>b:
        a,b=b,a
    while(b!=0):
        n=a%b
        a=b
        b=n
    return a
    