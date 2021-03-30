n = int(input())
n //= 3
ans = 0
for i in range(1,n-1):
    for j in range(1,n-1):
        if (i+j) < n:
            ans+=1

print(ans)