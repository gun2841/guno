#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace::std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    int n = record.size();
    vector<vector<string>> vt(n,vector<string>(3));
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        istringstream ss(record[i]);
        ss >> vt[i][0];
        ss >> vt[i][1];
        ss >> vt[i][2];
        if (vt[i][0] == "Enter" || vt[i][0] == "Change")
            mp[vt[i][1]] = vt[i][2];
    }
    for (int i = 0; i < vt.size(); i++)
    {
        if (vt[i][0] == "Enter")
        {
            answer.push_back(mp[vt[i][1]] + "님이 들어왔습니다.");
        }
        else if (vt[i][0] == "Leave")
            answer.push_back(mp[vt[i][1]] + "님이 나갔습니다.");
    }


    return answer;
}