#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < 91 )
		{
			ans += str[i] - 38;
		}
		else if (str[i] > 96)
		{
			ans += str[i] - 96;
		}
	}
	if (ans == 1)
		printf("It is a prime word.");
	else
	{
		for (int i = 2; i*i <= ans; i++)
		{
			if (ans%i == 0)
			{
				printf("It is not a prime word.");
				return 0;
			}
				
		}
		printf("It is a prime word.");
	}
	
}