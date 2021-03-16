def modComb(n,r,m):
    if n<r:
        return 0
    if n==0 or r == 0 or n ==r:
        return 1
    if n-r < r:
        r = n-r
    q = 1
    for i in range(1,r+1):
        q = q*n//i
        n-=1
    return q %m
def solve(n,r,m):
    if n==0 or r == 0 or n == r:
        return 1
    return solve(n//m,r//m,m) * modComb(n%m,r%m,m)%m

n,r ,m = map(int,input().split())
print(solve(n,r,m))