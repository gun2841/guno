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


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int s = skill.size();
    for (int i = 0; i < skill_trees.size(); i++)
    {
        int id = 0;
        bool check = true;
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            for (int a = 0; a < s; a++)
            {
                if (skill_trees[i][j] == skill[a])
                {
                    if (id == a)
                    {
                        id++;
                    }
                    else {
                        check = false;
                        break;
                    }
                }
            }
        }
        if (check)
            answer++;
    }
    return answer;
}