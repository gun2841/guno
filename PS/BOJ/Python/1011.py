tc = int(input())
for i in range(0,tc):
    a ,b = map(int, input().split())
    max = 1
    n=1
    len = b-a
    while len>max:
        max = max+n//2+1
        n+=1
    print(n)