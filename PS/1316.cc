#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int solve(string str)
{
	vector<char> stack;
	vector<char>::iterator iter;
	for (int i = 0; i < str.size(); i++)
	{
		if (stack.empty())
			stack.push_back(str[i]);
		else if (stack.back() == str[i])
			continue;
		else if (stack.back() != str[i])
		{
			iter = find(stack.begin(), stack.end(), str[i]);
			if (iter == stack.end())
				stack.push_back(str[i]);
			else
				return -1;
		}		
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, check=0;
	string str;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (solve(str) == 1)
			check++;
	}
	cout << check;
}