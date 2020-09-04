def solution(people, limit):
    answer = 0
    sorted(people)
    right = len(people)-1
    left = 0
    while(left < right+1):
        if (people[right]+people[left]) <= limit:
            left+=1
        right-=1
        answer+=1
        print(str(left) +" " + str(right))
    return answer