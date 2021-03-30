#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
#include <stack>
using namespace::std;
typedef pair<int, int> P;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int t=0;
    priority_queue <int,vector<int>, less <int >> pq;
    for (int i = 0; i < k; i++)
    {
        if (dates[t] == i){
            pq.push(supplies[t]);
        if (t != supplies.size() - 1)
            t++;
    }
        if (stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }
   
    return answer;
}