import heapq


def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while True:
        a = heapq.heappop(scoville)
        if a >= K:
            return answer
        if len(scoville) == 0 and a < K:
            return -1
        b = heapq.heappop(scoville)
        heapq.heappush(scoville, a+(b+b))
        answer+=1
    return answer