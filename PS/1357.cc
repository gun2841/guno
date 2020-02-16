#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int Rev(int num)
{
	char str[5];
	int len;
	int temp;
	sprintf(str, "%d", num);
	len = strlen(str);

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	temp = atoi(str);

	return temp;
}

int main()
{
	int X, Y;

	cin >> X >> Y;

	cout << Rev(Rev(X) + Rev(Y)) << endl;
}