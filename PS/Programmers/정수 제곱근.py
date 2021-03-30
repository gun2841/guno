import math
def solution(n):
    a= math.sqrt(n)
    if( a - int(a) == 0):
        return int((a+1)*(a+1))
    return -1