n = int(input())
ans = n
prime = 2
while prime*prime <= n:
    if (n% prime )== 0:
        ans = ans//prime * (prime-1)
    while n%prime == 0:
        n = n//prime
    prime+=1

if n != 1:
    ans = ans//n * (n-1)
print(ans)