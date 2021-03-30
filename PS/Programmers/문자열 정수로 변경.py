def solution(s):
    answer = 0
    liter = s[0]
    if(liter != '-'):
        return int(s)
    s = s[1:len(s)]
    return int(s)*-1
    