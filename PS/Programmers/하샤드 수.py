def solution(x):
    a = (list(str(x)))
    sum = 0
    for i in a:
        sum += int(i)
    if(x%sum == 0):
        return True
    return False