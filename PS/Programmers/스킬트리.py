def solution(skill, skill_trees):
    answer = 0
    for i in skill_trees:
        id = 0
        check = True
        for j in range(len(i)):
            for a in range(len(skill)):
                if i[j] == skill[a]:
                    if id == a: id+=1
                    else: 
                        check = False
                        break
        if check: answer += 1
    return answer