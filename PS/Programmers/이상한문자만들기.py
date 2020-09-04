def solution(s):
    answer = ''
    arr = s.split(" ")
    for i in arr:
        answer+=change(i)
        answer+= ' '
    answer=answer[0:len(answer)-1]
    return answer
def change(s):
    temp = ''
    for i in range(len(s)):
        if(i%2== 1):
            temp+=(s[i].lower())
        else:
            temp+=(s[i].upper())
    return temp