n = int(input())
arr = list(map(int,input().split()))

arr.sort()

print(arr[0]*arr[n-1])