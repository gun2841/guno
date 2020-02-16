#include <iostream>
using namespace::std;
int arr[101];
int main()
{
	ios_base::sync_with_stdio(false);
	int N, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (arr[a] == 0)
			arr[a] = 1;
		else if (arr[a] == 1)
			count++;
	}
	cout << count;
}