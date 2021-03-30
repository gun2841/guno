#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace::std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int tp = 0;
    int n = clothes.size();
    vector<int> vt;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(clothes[i][1]) == m.end())
        {
            m.insert(make_pair(clothes[i][1], 1));
        }
        else
            m[clothes[i][1]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        answer *= (it->second+1);
    }

        
    return answer-1;
}
