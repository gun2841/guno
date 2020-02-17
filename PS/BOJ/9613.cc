#include <iostream>
#include <stack>
#include <string>
using namespace::std;
long long gcd(long long a, long long b);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long arr[101], sum =0;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
			cin >> arr[i];

		for (int i = 0; i < num; i++)
			for (int j = i+1; j < num; j++)
				sum += gcd(arr[i], arr[j]);
		cout << sum<<endl;
	}
}
long long gcd(long long a, long long b)
{
	return (a%b == 0 ? b : gcd(b, a%b));
}