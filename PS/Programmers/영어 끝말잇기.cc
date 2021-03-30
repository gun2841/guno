#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace::std;


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0); answer.push_back(0);
    map<string,int> mp;
    int total = words.size();
    int idx = 2;
    int cycle = 1;
    mp.insert(make_pair(words[0], 1));
    char end=words[0][words[0].size()-1];

    for (int i = 1; i < total; i++)
    {
        if (end != words[i][0] || mp.find(words[i]) != mp.end())
        {
            answer[0] = idx;
            answer[1] = cycle;
            break;
        }
        end = words[i][words[i].size() - 1];
        mp.insert(make_pair( words[i], 1));
        idx++;
        if (idx > n) {
            cycle++;
            idx -= n;
        }
    }
    return answer;
}