def solution(a, b):
    answer = ''
    arr =[31,29,31,30,31,30,31,31,30,31,30,31]
    d = ["FRI","SAT","SUN", "MON","TUE","WED","THU"]
    pivot = -1
    for i in range(1,13):
        for j in range(1,arr[i-1]+1):
            pivot = (pivot+1)%7
            answer = d[pivot]
            if(i==a and j==b):
                return answer