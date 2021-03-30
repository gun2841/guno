#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
using namespace::std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int max = 0, size = 0;
    for (int i = 0; i < truck_weights.size(); i++)
    {
        size = truck_weights[i];
        while (1)
        {
            if (q.empty())
            {
                q.push(size); max += size; answer++;
                break;
            }
            else if (q.size() == bridge_length)
            {
                max -= q.front();
                q.pop();
            }
            else
            {
                if (size + max > weight)
                {
                    q.push(0); answer++;
                }
                else
                {
                    q.push(size); max += size;
                    answer++;
                    break;
                }

            }
        }
    }
   
    return answer+bridge_length;
}