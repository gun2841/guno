def combi(a,b):
    s = 1.0
    j  =b-a+1
    for i in range(a,b+1):
        s = s*float(i) /float(j)
        j-=1
    return s

t = int(input())
for i in range(0,t):
    n,m=map(int,input().split())
    print("%0.f" %combi(m-n+1,m))