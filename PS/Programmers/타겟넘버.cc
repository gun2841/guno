#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
using namespace::std;
int arr[20][2];
int ans = 0;
int n;
int tar;
void solve(int t, int pi)
{
    if (pi == n+1) {
        if(t==tar)
          ans++;

        return;
    }

    solve(t + arr[pi][0], pi + 1);
    solve(t + arr[pi][1], pi + 1);
}
int solution(vector<int> numbers, int target) {
    n = numbers.size();
    tar = target;
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = numbers[i];
        arr[i][1] = -numbers[i];
    }
    solve(0, 0);
    return ans;
}