#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace::std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> q;
    int n = cities.size();
    for (int i = 0; i < n; i++)
    {
        int s = q.size();
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        auto it = find(q.begin(), q.end(), cities[i]);

        if (it != q.end())
        {
            answer += 1;
            q.erase(it);
        }
        else
        {
            answer += 5;
            if (cacheSize == s && cacheSize != 0)
                q.erase(q.end());
        }
        if(cacheSize != 0) q.insert(q.begin(), cities[i]);
    }


    return answer;
}