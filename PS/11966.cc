#include <iostream>
#include <string>
#include <cmath>
#include<vector>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	ull arr[31];
	ull l = 1;
	for (int i = 0; i < 31; i++)
	{
		arr[i] = l;
		l *= 2;
	}
	cin >> l;

	for (int i = 0; i < 31; i++)
	{
		if (l == arr[i])
		{
			cout << "1";
			return 0;
		}
	}
	cout << "0";
}