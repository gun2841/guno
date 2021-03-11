def stran(h,m,s):
    return h*3600+m*60+s

def solve(s):
    h = s//3600
    m = (s-h*3600)//60
    ss = s%60
    print("{0} {1} {2}".format(h,m,ss))

for i in range(3):
    arr = list(map(int,input().split()))
    solve(stran(arr[3],arr[4],arr[5])-stran(arr[0],arr[1],arr[2]) )