n,m=map(int, input().split())

a=[0 for _ in range(n)]

for i in range(n):
    a[i]=list(map(int, input().split()))

n,m=map(int, input().split())
b=[0 for _ in range(n)]
for i in range(n):
    b[i]=list(map(int, input().split()))
def productMatrix(A, B):
    return [[sum(a*b for a, b in zip(A_row,B_col)) for B_col in zip(*B)] for A_row in A]

c = productMatrix(a,b)
for i in c:
    for j in i:
        print(j , end=' ')
    print()