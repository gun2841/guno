n = int(input())
answer = []
for i in range(n):
    str = input()
    if i == 0: answer = list(str)
    else:
        for i in range(len(str)):
            if answer[i] != str[i]:
                answer[i] = '?'

print(''.join(answer))