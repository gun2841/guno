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

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> vt1, vt2;
    int n = str1.size();
    for (int i = 0; i < n-1; i++)
    {
        char a= tolower(str1[i]), b= tolower(str1[i+1]);
        if (isalpha(a) && isalpha(b))
        {
            string str = "";
            str += a; str += b;
            vt1.push_back(str);
         //   cout << str << endl;
        }
    }
     n = str2.size();
    for (int i = 0; i < n - 1; i++)
    {
        char a = tolower(str2[i]), b = tolower(str2[i + 1]);
        if (isalpha(a) && isalpha(b))
        {
            string str = "";
            str += a; str += b;
            vt2.push_back(str);
         //   cout << str << endl;
        }
    }
    sort(vt1.begin(), vt1.end());
    sort(vt2.begin(), vt2.end());

    vector<string> result;
    result.resize(vt1.size()+vt2.size()+1);
    auto itr = set_union(vt1.begin(), vt1.end(), vt2.begin(), vt2.end(), result.begin());
    result.erase(itr, result.end());
    int a = result.size();
    result.clear();


    result.resize(vt1.size() + vt2.size());
    auto it = set_intersection(vt1.begin(), vt1.end(), vt2.begin(), vt2.end(), result.begin());
    result.erase(it, result.end());
    int b = result.size();
    if (a == 0 && b == 0)
        answer = 65536;
    else {
        double ans = (double)b / (double)a;
    //    cout << ans << endl;
      
        answer = ans * 65536;
    }

    return answer;
}