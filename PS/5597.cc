#include <iostream>
using namespace::std;
int arr[30];
int main()
{
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 28; i++)
	{
		int n;
		cin >> n;
		arr[n - 1] = 1;
	}

	for (int i = 0; i < 30; i++)
	{
		if (arr[i] != 1)
			cout << i + 1 << endl;
	}
}
