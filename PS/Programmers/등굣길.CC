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

int arr[102][102];
bool check[102][102];
int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            check[i][j] = true;
    for (int i = 0; i < puddles.size(); i++)
    {
        check[puddles[i][0]][puddles[i][1]] = false;
    }
    int a = 1;
    for (int i = 1; i <= m; i++) {
        if (!check[i][1])
            a = 0;
        arr[i][1] = a;

    }
    a = 1;
    for (int j = 1; j <= n; j++) {
        if (!check[1][j])
            a = 0;
        arr[1][j] = a;
    }

    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
        {
            int tp = 0;
            if (check[i - 1][j])
                tp = (tp + arr[i - 1][j]) % 1000000007;
            if (check[i][j - 1])
                tp = (tp + arr[i][j - 1]) % 1000000007;
            arr[i][j] = tp;

        }
    return arr[m][n] % 1000000007;
}