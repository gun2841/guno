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
struct st
{
    string head;
    string _h;
    string number;
    int num=0;
    string tail;
    int idx=0;
    void num_change()
    {
        num = stoi(number.c_str());
    }
    void upper()
    {
        for (int i = 0; i < head.size(); i++)
        {
            if (isupper(head[i]))
                _h += (head[i] + 32);
            else
                _h += head[i];
        }
    }
};
bool cmp(st a, st b)
{
    if (a._h > b._h)
        return false;
    if (a._h == b._h) {
        if (a.num > b.num)
            return false;
        else if (a.num < b.num)
            return true;
    }
    if (a._h == b._h && a.num == b.num)
        if (a.idx > b.idx)
            return false;
        
    return true;
}
vector<st> vt;
void input(string str,int id)
{
    st a;
    int n = str.size();
    int sw = 0;
    string s;
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(str[i]) && sw == 0)
        {
            s += str[i];
        }
        else if (isdigit(str[i]) && sw == 0)
        {
            a.head = s;
            s = "";
            s += str[i];
            sw = 1;
        }
        else if (sw == 1 && isdigit(str[i]))
        {
            s += str[i];
        }
        else if (sw == 1 && !isdigit(str[i]))
        {
            sw = 2;
            a.number = s;
            s = "";
            s += str[i];
        }
        else if (sw == 2)
        {
            s += str[i];
        }
    }
    if (sw == 1)
    {
        a.number = s;
    }
    else
    {
        a.tail = s;
    }
    a.num_change();
    a.upper();
    a.idx = id;
    vt.push_back(a);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    for (int i = 0; i < files.size(); i++)
    {
        input(files[i],i);
    }
    sort(vt.begin(), vt.end(),cmp);
    for (int i = 0; i < vt.size(); i++) {
        string s;
        s += vt[i].head;
        s += vt[i].number;
        s += vt[i].tail;
        answer.push_back(s);
    }

    return answer;
}