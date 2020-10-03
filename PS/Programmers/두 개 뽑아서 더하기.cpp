#include <string>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> mp;
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            int temp = numbers[i] + numbers[j];
            if (mp.find(temp) == mp.end()) {
                mp[temp] = 1;
                answer.push_back(temp);
            }
        }
    sort(answer.begin(), answer.end());
    return answer;
}