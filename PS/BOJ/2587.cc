#include <iostream>
#include <algorithm>
using namespace::std;
int str[50][3];
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[5];
	int v=0, mid;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		v += arr[i];
	}
	cout << v / 5 << endl;
	sort(arr, arr + 5);
	cout << arr[2];

}