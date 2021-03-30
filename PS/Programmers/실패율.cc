#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
using namespace::std;
struct score
{
    int idx;
    float sc;
};
bool compare(score a, score b)
{
    if (a.sc > b.sc)
        return true;
    if (a.sc == b.sc)
        if (a.idx < b.idx)
            return true;
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> ans(N + 2, 0);
    vector<score> vt;
    int total = stages.size();
    int index = stages.size();
    for (int i = 0; i < index; i++)
    {
        ans[stages[i]]++;
    }
    for (int i = 1; i <= N; i++)
    {
        score s;
        s.idx = i;
        if (ans[i] == 0)
            s.sc = 0;
        else {
            s.sc = (float)ans[i] / (float)total;
         //   cout << i << " " << ans[i] << " " << total << endl;
        }
        total -= ans[i];
        vt.push_back(s);
    }
    sort(vt.begin(), vt.end(), compare);
    for (int i = 0; i < vt.size(); i++) {
         answer.push_back(vt[i].idx);
       //cout << vt[i].idx <<  " " << vt[i].sc << endl;
    }
    return answer;
}