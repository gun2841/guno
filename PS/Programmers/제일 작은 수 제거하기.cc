#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int min = arr[0];
	int index;
	for (int i = 0; i < arr.size(); i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	vector<int>::iterator it;
	for (it = arr.begin(); it != arr.end();)
	{
		if (*it == min)
		{
			it = arr.erase(it);
		}
		else {
			it++;
		}
	}
    if(arr.empty())
        arr.push_back(-1);
	return arr;
}