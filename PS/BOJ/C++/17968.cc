#include <iostream>
using namespace::std;
int arr[1001] = {1,1,2,1,1,2,2,4,4, };
int main()
{
	for (int i = 3; i < 1001; i++)
	{
		int key = 1;
		while (1)
		{
			arr[i] = key;
			int k = 1;
			while (1) {
				if (i - 2 * k < 0) break;
				if (arr[i] - arr[i - k] == arr[i - k] - arr[i - 2 * k])
					break;
				k++;
			}
			if (i - 2 * k < 0)
				break;
			else
				key++;
		}
	}

	int n;
	cin >> n;
	cout << arr[n] << endl;
}