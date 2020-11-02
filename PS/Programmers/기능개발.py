import math
def solution(progresses, speeds):
    answer = []
    li = []
    for i in range(len(progresses)):
        li.append(math.ceil((100-progresses[i]) /(speeds[i])))
    now = li[0]
    cnt = 1
    for i in range(1,len(li)):
        if( now >= li[i] ):
            cnt+=1
        else:
            answer.append(cnt)
            cnt = 1
            now = li[i]
    answer.append(cnt)
    return answer