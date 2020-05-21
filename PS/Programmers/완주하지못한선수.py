def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    n = 0
    for i in range(len(completion)):
        if participant[n] == completion[i]:
            n+1
    return participant[n]