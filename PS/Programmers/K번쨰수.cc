#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int len = commands.size();

	for (int i = 0; i < len; i++)
	{
		vector<int> copy_arr;
		copy_arr.assign(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);

		sort(copy_arr.begin(), copy_arr.end());

		answer.push_back(copy_arr[commands[i][2]-1]);
	}

	return answer;
}