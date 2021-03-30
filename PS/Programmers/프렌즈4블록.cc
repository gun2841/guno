#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
using namespace::std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = false;
    while (!check)
    {
        vector<vector<bool>> arr(m, vector<bool>(n));
        check = true;
        for(int i =0;i<m-1;i++)
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == 0)
                    continue;
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 1][j + 1]))
                {
                    arr[i][j] = arr[i + 1][j] = arr[i + 1][j + 1] = arr[i][j + 1] = 1;
                    check = false;
                }
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    answer++;
                    for (int k = i - 1; k >= 0; k--)
                    {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
    }
    return answer;
}