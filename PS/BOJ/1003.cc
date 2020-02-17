#include <iostream>
using namespace::std;
int main()
{
	unsigned long long arr[41][2] = {{1,0},
	{0,1},
	};
	for (int i = 2; i < 41; i++)
	{
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << arr[N][0] << " " << arr[N][1] << endl;
	}

	return 0;
}
