#include<iostream>
#include<cstdio>
#include<queue>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> vt;
    vector<string> revt;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        vt.push_back(s);
        reverse(s.begin(), s.end());
        revt.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

             if (vt[i] == revt[j])
            {
                cout << vt[i].size()<< " " << vt[i][vt[i].size() / 2];
                return 0;
            }
        }
    }
}
