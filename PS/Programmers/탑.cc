#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	answer.push_back(0);
	for (int i = 1; i < heights.size(); i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (heights[i] < heights[j])
			{
				answer.push_back(j+1);
				break;
			}
			else if (j == 0)
			{
				answer.push_back(0);
				break;
			}
		}
	}
	return answer;
}