import math
a = int(input())
for i in range(a):
    x1,y1,r1,x2,y2,r2 = map(int, input().split())
    if x1 == x2 and y1 ==y2:
        if r1==r2:
            print("-1")
        else:
         print("0")
    else:
        min = abs(r1-r2)
        d = math.sqrt((x2 - x1)*(x2-x1)+(y2-y1)*(y2-y1))
        if d<(r1+r2) and d> min:
            print("2")
        elif d == (r1+r2) or d == min:
            print("1")
        else:
            print("0")