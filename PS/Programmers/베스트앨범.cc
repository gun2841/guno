#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
using namespace::std;
struct st
{
    int total;
    int a=-1;
    int b=-1;
    int ai=-1, bi=-1;
    void max(int x,int y)
    {
        if (x > a)
        {
            b = a;
            a = x;
            bi = ai;
            ai = y;
        }
        else if (x == b)
        {
        }
        else if (x > b)
        {
            b = x; bi = y;
        }
        else if (x == a)
        {
            b = x; bi = y;
        }
    }

};
bool cmp(st a, st b)
{
    if (a.total > b.total)
        return true;

    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, st> m1;
    vector<st> vt;
    int n = genres.size();
    for (int i = 0; i < n; i++)
    {
        if (m1.find(genres[i]) == m1.end()) {
            st str;
            str.a = plays[i]; str.ai = i;
            str.total = plays[i];
            m1.insert(make_pair(genres[i], str));
        }
        else
        {
            m1[genres[i]].max(plays[i], i);
            m1[genres[i]].total += plays[i];
        }
         
    }
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        vt.push_back(it->second);
    }
    sort(vt.begin(), vt.end(),cmp);
    for (auto it = vt.begin(); it != vt.end(); it++)
    {
        int fst = it->ai;
        int snd = it->bi;
        if (fst != -1)
            answer.push_back(fst);
        if (snd != -1)
            answer.push_back(snd);

    }
    return answer;
}

