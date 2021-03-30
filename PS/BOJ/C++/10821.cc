#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string S;
	cin >> S;
	int count = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == ',')
			count++;
	}
	cout << count + 1;
}
