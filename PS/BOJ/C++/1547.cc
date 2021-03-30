#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[3] = { 1,0,0 };
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;

		int temp = arr[x - 1];
		arr[x - 1] = arr[y - 1];
		arr[y - 1] = temp;

	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == 1)
			cout <<  i + 1;
	}
}
