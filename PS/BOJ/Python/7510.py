n = int(input())
def solve(a,b,c):
    if a*a + b*b == c*c:
        return "yes"
    return "no"
for i in range(n):
    arr = list(map(int, input().split()))
    arr.sort()
    print("Scenario #{0}:".format(i+1) )
    print(solve(arr[0],arr[1],arr[2]))
    print()