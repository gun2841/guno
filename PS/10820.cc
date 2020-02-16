#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str;
	int arr[4] = { 0,0,0,0 };
	while (1)
	{
		getline(cin , str);
		if (str[0] == '\0')
			break;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				arr[0]++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				arr[1]++;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				arr[2]++;
			}
			else if (str[i] == ' ')
			{
				arr[3]++;
			}
		}
		for (int i = 0; i < 4; i++) {
			printf("%d ", arr[i]);
			arr[i] = 0;
		}
		printf("\n");
	}
}