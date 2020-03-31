#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace::std;
int dp[100][1000001];
int solution(int K, vector<vector<int>> travel) {
    int n = travel.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[0][travel[i][0]] = travel[i][1];
            dp[0][travel[i][2]] = travel[i][3];
        }
        else
            for (int j = 0; j < K; j++)
            {
                if (!dp[i - 1][j]) continue;
                if (j + travel[i][0] <= K) dp[i][j + travel[i][0]] = max(dp[i][j + travel[i][0]], dp[i - 1][j] + travel[i][1]);
                if (j + travel[i][2] <= K) dp[i][j + travel[i][2]] = max(dp[i][j + travel[i][2]], dp[i - 1][j] + travel[i][3]);
            }
   }
    int answer = 0;
    for (int i = 0; i <= K; i++)
        if (answer < dp[n - 1][i])
            answer = dp[n - 1][i];
    return answer;
}