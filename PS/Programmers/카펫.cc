#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace::std;


vector<int> solution(int brown, int red) {
    vector<int> answer;
    int d = brown + red;
    vector<int> n;
    for (int i = 2; i * i <= d; i++)
        if (d % i == 0)
            n.push_back(d / i);

    for (int i = 0; i < n.size(); i++)
    {
        int m = d / n[i];
        int y = (n[i] - 2) * (m - 2);
        int x = n[i]*m-y;
        if (x == brown && y == red)
        {
            answer.push_back(n[i]);
            answer.push_back(m);
        }
    }

    return answer;
}