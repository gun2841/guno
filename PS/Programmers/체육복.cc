#include <string>
#include <vector>

using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> arr(n+2,1);
    for(int i =0 ;i<lost.size();i++)
        arr[lost[i]]--;
    for(int i = 0 ;i<reserve.size();i++)
        arr[reserve[i]]++;

    for(int i =1 ;i<=n;i++)
    {
        if(arr[i] == 1 || arr[i] == 2)
        {
            answer+=1;
        }
        else if(arr[i] == 0)
        {
            if(arr[i-1] == 2)
            {
                arr[i-1]--;
                arr[i]++;
                answer++;
            }
            else if(arr[i+1] == 2)
            {
                arr[i+1]--;
                arr[i]++;
                answer++;
            }
        }
    }

    return answer;
}