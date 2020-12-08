def solution(bridge_length, weight, truck_weights):
    answer = 0
    que = []
    max = 0
    for i in range(len(truck_weights)):
        size = truck_weights[i];
        while True:
            if len(que) == 0:
                que.append(size)
                max+=size
                answer+=1
                break
            elif len(que) == bridge_length:
                max -= que.pop(0)
            else:
                if (size+max)>weight:
                    que.append(0)
                    answer+=1
                else:
                    que.append(size)
                    max+=size
                    answer+=1
                    break
    return answer+bridge_length