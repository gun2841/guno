#include <iostream>
using namespace::std;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	int arr[100];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < T; i++)
	{
		int r = gcd(arr[0], arr[i]);
		cout << arr[0] / r << "/" << arr[i] / r << endl;
	}
}
