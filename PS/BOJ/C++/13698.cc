
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
int arr[5] = {0,1,0,0,2};
void swap(int first, int second)
{
	int temp =arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case 'A':
			swap(1, 2);
			break;
		case 'B':
			swap(1, 3);
			break;
		case 'C':
			swap(1, 4);
			break;
		case 'D':
			swap(2, 3);
			break;
		case 'E':
			swap(2, 4);
			break;
		case 'F':
			swap(3, 4);
			break;
		default:
			break;
		}
	}
	for (int i = 1; i < 5; i++)
		if (arr[i] == 1)
			cout << i << endl;

	for (int i = 1; i < 5; i++)
		if (arr[i] == 2)
			cout << i;
}