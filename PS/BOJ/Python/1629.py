a,b,c= map(int,input().split())

def calc(a,b,c):
    if b == 0: return 1
    elif b == 1: return a%c

    if(b%2 == 1):
        temp = calc(a,b//2,c)
        return temp*temp*a%c
    else:
        temp = calc(a,b//2,c)
        return temp*temp%c

print(calc(a,b,c))