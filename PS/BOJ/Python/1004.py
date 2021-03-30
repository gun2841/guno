t = int(input())
for i in range(0,t):
    cnt = 0
    x1,y1,x2,y2 = map(int, input().split())
    n = int(input())
    for j in range(0,n):
        cx,cy,r = map(int,input().split())
        tmp = ((x1-cx)*(x1-cx) + (y1-cy)*(y1-cy) - r*r) *((x2-cx) * (x2-cx) + (y2-cy)*(y2-cy)-r*r)
        if tmp<=0:
            cnt+=1
    print(cnt)