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
int dp[1000003][2];
int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    dp[0][0] = money[0]; dp[1][0] = money[0];
    dp[0][1] = 0; dp[1][1] = money[1];
    for (int i = 2; i < n; i++)
    {
 
            dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
    }
    return max(dp[n-2][0], dp[n-1][1]);
}