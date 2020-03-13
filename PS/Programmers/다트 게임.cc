#include <string>
#include <algorithm>
using namespace std;
int solution(string dartResult) {
    int answer = 0;
    int arr[3];
    bool acha[3]={false,false,false};
    int star[3] ={1,1,1};
    int cnt =0;
    string a = "";
    for(int i = 0;i<dartResult.size();i++)
    {
        if('0' <= dartResult[i] && '9' >= dartResult[i])
            a+=dartResult[i];
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            char c = dartResult[i];
            int d = atoi(a.c_str());
            if(c == 'S')
                arr[cnt] = d;
            else if(c=='D')
                arr[cnt] = d*d;
            else
                arr[cnt] = d*d*d;

            if(dartResult[i+1] == '#')
                acha[cnt]= true;
            if(dartResult[i+1] == '*')
            {
                if(cnt == 0)
                    star[0]*=2;
                else if(cnt == 1)
                {
                    star[0]*=2; star[1]*=2;
                }
                else if(cnt ==2)
                {
                    star[1]*=2;star[2]*=2;
                }
                
            }   
            cnt++;
            a="";
        }
    }
    for(int i =0;i<3;i++)
    {
        if(acha[i] == true)
        arr[i] = arr[i] * -1;
         arr[i]*=star[i];
         answer +=arr[i];
    }
    return answer;
}