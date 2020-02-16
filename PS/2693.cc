#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[10];
	int T;
	cin >> T;
	while (T--)
	{
		int n; 
		for (int i = 0; i < 10; i++)
		{
			cin >> n; arr[i] = n;
		}
		sort(arr, arr + 10);
		cout << arr[7] << endl;
	}
}
