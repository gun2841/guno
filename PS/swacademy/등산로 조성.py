T = int(input())
dir = [[1 , 0],[0,1],[-1,0],[0,-1]]
for test_case in range(1, T + 1):
    n, k = map(int, input().split())
    answer = 0
    arr = [list(map(int, input().split())) for i in range(n)]
    check = [[False for i in range(n)] for j in range(n)]
    high = max(map(max,arr))

    def dfs(x,y,len,dig):
       global answer, n
       if len > answer: answer = len

       for li in dir:
           nx ,ny = x+li[0], y+li[1]
           if (nx < 0 or ny < 0 or nx >= n or ny >= n): continue
           if check[nx][ny]: continue
           if arr[x][y] <= arr[nx][ny] and dig == 0:
               for j in range(k):
                   temp = arr[nx][ny]
                   next = arr[nx][ny]-j-1
                   if arr[x][y] > next:
                        arr[nx][ny] ,check[nx][ny]=next, True
                        dfs(nx,ny,len+1,j+1)
                        arr[nx][ny],check[nx][ny] = temp,False
           elif arr[x][y] > arr[nx][ny]:
               check[nx][ny] = True
               dfs(nx,ny,len+1,dig)
               check[nx][ny] = False

    for i in range(n):
        for j in range(n):
           if arr[i][j] == high:
               check[i][j] = True
               dfs(i,j,1,0)
               check[i][j] = False

    print("#%d" %test_case, answer)