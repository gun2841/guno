def solution(n):
    answer = 0
    pivot = 1
    ans = ""
    while n != 0:
        ans+=str(n%3)
        n//=3
    for i in ans[::-1]:
        answer+=(int(i) * pivot)
        pivot*=3
    return answer