#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> ans(n);
    for(int i = 0;i<n;i++)
    {
        ans[i] = arr1[i] | arr2[i];
        string tp = "";
        int cnt = n;
        while(cnt--)
        {
            if(ans[i]%2 == 1)
                tp+= "#";
            else
                tp+=" ";
                ans[i]/=2;
        }
        reverse(tp.begin(),tp.end());
        answer.push_back(tp);
    }

    return answer;
}