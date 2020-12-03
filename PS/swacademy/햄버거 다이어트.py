import math
T = int(input())
for test_case in range(1, T + 1):
    N,L = map(int, input().split())
    answer = 0
    arr = []
    for i in range(N):
        t,k = map(int,input().split())
        arr.append((t,k))

    def solve(idx,cal,score):
        global answer,L
        if idx == N:
            if score > answer: answer = score
            return
        if cal + int(arr[idx][1]) <= L:
            solve(idx+1,cal+int(arr[idx][1]), score+int(arr[idx][0]))
        solve(idx + 1, cal, score)
    for i in range(N):
        solve(i,0,0)
        pass
    #print(answer)
    print("#%d" % test_case, answer)