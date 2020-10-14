#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;
#define abs(x) x<0 ? -x : x
#define dddd 0.001
vector<string> token(string str, char del)
{
    vector<string> tmp;
    string token;
    stringstream ss(str);
    while (getline(ss, token, del))
    {
        tmp.push_back(token);
    }
    return tmp;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<double>> list;
    int n = lines.size();
    for (int i = 0; i < n; i++)
    {
        vector<string> tmp = token(lines[i], ' ');

        vector<string> time = token(tmp[1], ':');
        double start = stod(time[0]) * 3600 + stod(time[1]) * 60 + stod(time[2]);
        double dist = stod(token(tmp[2], 's')[0]);

        list.push_back({ start - dist + 0.001,start });
    }
    for (int i = 0; i < n; i++)
    {
        double start = list[i][1];
        double end = start + 0.999;
        //cout << start << " " << end << endl;
        int tmp = 0;
        for (int j = i; j < n; j++) {
            //cout << abs(list[j][1] - start) << " " << abs(list[j][0]-end)<< endl;
             if (abs(list[j][1] - start) >= dddd && abs(list[j][0] - end) <= dddd) tmp++;
        }
        answer = max(answer, tmp);
    }
    return answer;
}