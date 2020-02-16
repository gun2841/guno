#include <iostream>
#include <string>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		int t;
		cin >> t >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (j == t - 1)
				continue;
			else
				cout << str[j];
		}
		cout << endl;
	}
}
