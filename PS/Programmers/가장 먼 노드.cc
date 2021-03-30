#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
using namespace::std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int>());
    vector<int> dist(n + 1);
    vector<bool> visit(n + 1);
    queue<int> q;
    for (int i = 0; i < edge.size(); i++)
    {   
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    visit[1] = true;
    dist[1] = 0;
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        for (int i = 0; i < arr[start].size(); i++)
        {
            if (visit[arr[start][i]] == false)
            {
                q.push(arr[start][i]);
                visit[arr[start][i]] = true;
                dist[arr[start][i]] = dist[start] + 1;
            }
        }
    }
    sort(dist.begin(), dist.end());
    int max = dist.back();
    for (int i = 1; i <= n; i++)
        if (dist[i] == max)
            answer++;
    return answer;
}