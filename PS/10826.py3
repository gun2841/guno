a = 0
b = 1
result = 0;
n = int(input())
i = n
while n > 1:
    result = (a+b)
    a=(b)
    b=(result)
    n-=1
if i == 1:
    print(1)
else:
    if i == 2:
        print(1)
    else:
        print(result)