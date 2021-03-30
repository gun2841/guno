#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int right = people.size()-1, left =0;
	while (left < right+1)
	{
		if (people[right] + people[left] <= limit)
			left++;
		right--;
		answer++;
	}
	return answer;
}