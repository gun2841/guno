def solution(s, n):
    s=list(s)
    for i in range(len(s)):
        if s[i].isupper():
            s[i] = chr((ord(s[i])+n-65)%26+65)
        if s[i].islower():
            s[i] = chr((ord(s[i])+n-97)%26+97)
    return ''.join(s)