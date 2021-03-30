n = int(input())
arr = list(map(int,input().split()))
brr = list(map(int, input().split()))

arr.sort()
brr.sort(reverse=True)

answer = 0
for i in range(n):
    answer+= arr[i]*brr[i]

print(answer)