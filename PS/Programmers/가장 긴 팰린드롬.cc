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
int arr[100001];
string str;
void manachers(string s, int n)
{
    int r = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= r)
            arr[i] = min(arr[2 * p - i], r - i);
        else
            arr[i] = 0;

        while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < n && s[i - arr[i] -1] == s[i + arr[i] + 1])
            arr[i]++;

        if (r < i + arr[i])
        {
            r = i + arr[i];
            p = i;
        }
    }
}
int solution(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        str += '#';
        str += s[i];
    }
    str += '#';
    n = str.size();
    manachers(str, n);
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i]);

    return ans;
}