#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> weight) {
	int answer = 0;
	sort(weight.begin(), weight.end());
	if (weight[0] != 1)
		return 1;
	
	int sum = 1;
	for (int i = 1; i < weight.size(); i++)
	{
		if (weight[i] > sum + 1)
			break;
		sum += weight[i];
	}

	return sum+1;
}