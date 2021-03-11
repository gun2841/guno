#include <iostream>
using namespace::std;
int main()
{
	int total = 0, input =0;
	for (int i = 0;i < 4;i++)
	{
		cin >> input;
		total += input;
	}
	cout << total / 60 << endl;
	cout << total % 60;
}


