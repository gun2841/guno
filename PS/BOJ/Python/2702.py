from math import gcd
n = int(input())
for i in range(n):
    a,b = map(int, input().split())
    g = gcd(a,b)
    print("{0} {1}".format(a*b//g ,g))