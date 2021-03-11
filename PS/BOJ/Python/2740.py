a ,b = 1,2
n = int(input())
print(n)

for i in range(n):
    a,b = b, a+b

print(a , b)