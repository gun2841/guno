#include <iostream>
using namespace::std;
int arr[1000];
int brr[1000];
int main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned long long a, sum = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= 2;

	for (int i = 1; i < a; i = i + 2)
	{
		sum -= arr[i];
	}
	cout << sum << endl;
	brr[0] = sum;
	for (int i = 1; i < a; i++)
	{
		brr[i] = arr[i-1] - brr[i - 1];
		cout << brr[i] << endl;
	}

}