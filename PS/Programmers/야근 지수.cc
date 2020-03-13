#include <string>
#include <vector>
#include <queue>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++)
    {
        pq.push(works[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            break;
        long long temp = pq.top();
        pq.pop();
        temp-=1;
        if(temp>=0)
          pq.push(temp);
    }
    while (!pq.empty())
    {
        long long temp = pq.top();
        pq.pop();
        if(temp != 0)
            answer += temp * temp;
    }
    return answer;
}