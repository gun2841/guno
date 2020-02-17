#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int a[5] = { 1,2,3,4,5 };
	int b[8] = { 2,1,2,3,2,4,2,5};
	int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int arr[3] = { 0,0,0 };


	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == a[(i % 5)])
			arr[0]++;
		if (answers[i] == b[(i % 8)])
			arr[1]++;
		if (answers[i] == c[(i % 10)])
			arr[2]++;
	}
	int max = 0;
	if (arr[0] > max)
		max = arr[0];
	if (arr[1] > max)
		max = arr[1];
	if (arr[2] > max)
		max = arr[2];
	if (arr[0] == max)
		answer.push_back(1);
	if (arr[1] == max)
		answer.push_back(2);
	if (arr[2] == max)
		answer.push_back(3);

	return answer;
}