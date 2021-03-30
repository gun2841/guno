import sys; sys.setrecursionlimit(10000)
n = int(input())
for i in range(n):
    m,n,k = map(int, input().split())
    arr = [[0 for _ in range(50)] for _ in range(50)]
    answer = 0
    def recur(x,y):
        if x < 0 or y < 0 or x >= n or y >= m:
            return
        if arr[x][y] == 0: return
        if arr[x][y] == 1: arr[x][y] = 0

        recur(x+1,y)
        recur(x-1,y)
        recur(x,y+1)
        recur(x,y-1)

    for j in range(k):
        x,y = map(int,input().split())
        arr[y][x] = 1

    for x in range(n):
        for y in range(m):
            if arr[x][y] == 1:
                answer+=1
                recur(x,y)
    print(answer)