import math
matrix = [[0]*2 for i in range(41)]
matrix[0][0] =1
matrix[0][1] = 0
matrix[1][0] = 0
matrix[1][1] = 1

for i in range(2,41):
    matrix[i][0] = matrix[i-2][0] + matrix[i-1][0]
    matrix[i][1] = matrix[i-2][1] + matrix[i-1][1]

a = int(input())
for i in range(a):
    n = int(input())
    print(matrix[n][0],matrix[n][1])