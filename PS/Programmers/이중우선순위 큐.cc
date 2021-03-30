#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
#include <stack>
#include <sstream>
using namespace::std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for (int i = 0; i < operations.size(); i++)
    {
        stringstream a;
        string fst;
        a.str(operations[i]);
        a >> fst;
        int num;
        if (fst == "I")
        {
            a >> fst;
            num = stoi(fst.c_str());
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else
        {
            if (dq.empty())
                continue;
            a >> fst;
            if (fst == "1")
            {
                dq.pop_back();
            }
            else
            {

                dq.pop_front();
            }
        }
    }
    if (dq.empty())
        dq.push_back(0);

    answer.push_back(dq.back());
    answer.push_back(dq.front());

    return answer;
}