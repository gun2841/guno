#include <iostream>
#include <string>
using namespace::std;
int arr[26];
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		arr[str[0] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			printf("%c", i + 97);
			T = 1;
		}
	}
	if (T != 1)
		printf("PREDAJA");
}
