T = int(input())
dir = [[ -1 , 0] , [-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1]]

for test_case in range(1, T + 1):
    N = int(input())
    answer = 0
    arr = []
    check = [[0 for i in range(N)] for j in range(N)]
    for i in range(N):
        temp =input()
        arr.append(list(temp))
    def mine(x,y):
        for idx in dir:
            nx, ny = x + idx[0], y + idx[1]
            if nx >= 0 and nx < N and ny >= 0 and ny < N:
                if arr[nx][ny] == '*':
                    return False
        return True
    def dfs(x,y):
        if check[x][y] == 1:
            return

        check[x][y] = 1
        cnt = 0
        exist = 0
        for idx in dir:
            nx,ny = x+idx[0],y+idx[1]
            if nx >= 0 and nx < N and ny >=0 and ny < N:
               if arr[nx][ny] == '*':
                   cnt+=1
        if cnt == 0:
            for idx in dir:
                nx, ny = x + idx[0], y + idx[1]
                if nx >= 0 and nx < N and ny >= 0 and ny < N:
                    dfs(nx,ny)

        arr[x][y] = '^'

    for i in range(N):
        for j in range(N):
            if arr[i][j] == '.':
                if mine(i,j) == True:
                    dfs(i,j)
                    answer+=1
    for i in range(N):
        for j in range(N):
            if arr[i][j] == '.':
                answer+=1

    print("#%d" % test_case, answer)
