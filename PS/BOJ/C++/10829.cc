#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace::std;
int arr[1001][1001];
int main()
{
	unsigned long long N; cin >> N;
	string str;
	while (N != 0)
	{
		if (N % 2 == 1)
			str += "1";
		else
			str += "0";
		N /= 2;
	}
	reverse(str.begin(), str.end());
	cout << str;
}