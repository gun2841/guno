#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    vector<vector<int>> temp(len, vector<int>(4, 0));
    for (int i = 0; i < 4; i++)
        temp[0][i] = land[0][i];

    for(int i =1;i<len;i++)
        for(int j = 0;j<4;j++)
            for (int k = 0; k < 4; k++)
            {
                if(j!=k)
                temp[i][j] = max(temp[i][j], temp[i - 1][k] + land[i][j]);
            }
    for (int i = 0; i < 4; i++)
        answer = max(answer, temp[len - 1][i]);
    return answer;
}