def solution(board, moves):
    answer = 0
    m = len(board)
    st = []
    st_point = 0
    for i in moves:
        for j in range(m):
            if board[j][i-1] != 0:
                st.append(board[j][i-1])
                board[j][i-1] = 0
                st_point+=1
                if(st_point > 1) and (st[st_point-1] == st[st_point-2]):
                    del st[st_point-1]
                    del st[st_point-2]
                    st_point-=2
                    answer+=2
                break
    return answer