#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace::std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int m = board[0].size();
    int n = board.size();
    stack<int> st;
    vector<queue<int>> vt(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                continue;

            vt[j].push(board[i][j]);
        }


    for (int i = 0; i < moves.size(); i++)
    {
        int t = moves[i] - 1; // 
        if (vt[t].empty())
            continue;

        int x = vt[t].front();

        if (st.empty())
        {
            st.push(x);
            vt[t].pop();
        }
        else
        {
            if (st.top() == x)
            {
                st.pop();
                answer += 2;
            }
            else
                st.push(x);
            vt[t].pop();
        }
    }

    return answer;
}