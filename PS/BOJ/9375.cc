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
#include <set>
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
        answer *= (it->second + 1);
    }
    return answer - 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<vector<string>> vt;
        for (int j = 0; j < m; j++)
        {
            vector<string> temp(2);
            cin >> temp[0] >> temp[1];
            vt.push_back(temp);
        }
        cout << solution(vt) << "\n";
    }

}