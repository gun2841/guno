#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mp;
    int n = msg.size();
    int idx = 1;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        string temp; temp += char(i);
        mp[temp] = idx; idx++;
    }
    bool check = true;
    int j;
    for (int i = 0; i < n; i++)
    {
        check = true;
        string temp = "";
        while (check)
        {
            temp += msg[i];
            if (mp.find(temp) != mp.end())
            {
                j = mp[temp];
                i++;
            }
            else {
                check = false;
                answer.push_back(j);
               // cout << mp[temp] << endl;
                if (mp[temp] == 0) {
                    mp[temp] = idx;
                    idx += 1;
                }
                i--;
            }
        }
    }
    return answer;
}
