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
int solution(vector<int> cookie) {
    int answer = 0;
    int s = cookie.size();
    vector<int > vt(s + 1, 0);
    for (int i = 0; i < s; i++) {
        vt[i + 1] = cookie[i] + vt[i];
    }
    int l = 1, m = 1, n = 2;
    for (n = 2; n <= s; n++)
        for (m = 1; m < n; m++) {
            if (vt[m] - vt[0] < vt[n] - vt[m])
                continue;
            for (l = 1; l <= m; l++)
            {
                if (vt[n] - vt[m] < answer)
                    break;
                if (vt[m] - vt[l - 1] < vt[n] - vt[m])
                    break;
                if (vt[m] - vt[l - 1] == vt[n] - vt[m])
                {
                    answer = max(answer, vt[m] - vt[l - 1]);
                }
            }
        }
    return answer;
}