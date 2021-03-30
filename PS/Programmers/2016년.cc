#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int arr[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> d = {"FRI","SAT","SUN", "MON","TUE","WED","THU"};
    int pivot = -1;
    for(int i =1;i<=12;i++)
    {
        for(int j =1;j<=arr[i-1];j++)
        {
            
            pivot = (pivot+1)%7;
            answer = d[pivot];
            if(i==a && j==b)
            {
                return answer;
            }
        }
    }
}