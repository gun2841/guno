#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[1001][1001];
void solve(int n)
{
    int max = n * (n + 1) / 2;
    int i = 0,j=0, ins=1;
    int state = 0, repeat = n;
    while (ins != max+1)
    {
        if (state == 0)
        {
            for (int k = 0; k < n; k++)
                arr[i++][j] = ins++;
            state = 1;
            n--;
            i -= 1; j += 1;
        }
        else if (state == 1)
        {
            for (int k = 0; k < n; k++)
                arr[i][j++] = ins++;
            state = 2;
            n--;
            i -= 1; j -= 2;
        }
        else if (state == 2)
        {
            for (int k = 0; k < n; k++)
                arr[i--][j--] = ins++;
            n--;
            i += 2; j += 1;
            state = 0;
        }
    }
}
vector<int> solution(int n) {
    vector<int> answer;
    solve(n);
    for(int i =0;i<n;i++)
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(arr[i][j]);
        }
    return answer;
}