#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	char ch = 'Y';
	int arr[5], brr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> brr[i];
	}
	for (int i = 0; i < 5; i++)
	{
		if (1 - arr[i] != brr[i])
			ch = 'N';
	}
	cout << ch;
}