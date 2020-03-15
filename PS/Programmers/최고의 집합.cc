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

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    int d = s / n;
    int a = s % n;
    answer.assign(n, d);
    n -= 1;
    for (int i = a; i > 0; i--)
        answer[n--]++;
 
    return answer;
}