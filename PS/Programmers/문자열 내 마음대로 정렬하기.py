def solution(strings, n):
    s = sorted(strings)
    answer = sorted(s, key=lambda x:x[n])
    return answer