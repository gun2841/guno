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


int dp[100003][2];
int solution(vector<int> sticker) {
    int answer = 0;
    int n = sticker.size();
    if (n == 1)
        return sticker[0];
    dp[0][0] = sticker[0]; dp[1][0] = sticker[0];
    dp[0][1] = 0; dp[1][1] = sticker[1];
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = max(dp[i - 2][0] + sticker[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 2][1] + sticker[i], dp[i - 1][1]);
    }
    return max(dp[n - 2][0], dp[n - 1][1]);
}