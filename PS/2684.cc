#include <iostream>
#include <string>
using namespace::std;

int main()
{	
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string str;
		int arr[8] = { 0,0,0,0,0,0,0,0 };
		cin >> str;

		for (int i = 0; i < str.size()-2; i++)
		{
			int a = 0;
			if (str[i] == 'H') {
				a += 4;
			}

			if (str[i+1] == 'H') {
				a += 2;
			}
	
			if (str[i+2] == 'H') {
				a += 1;
			}
			arr[a]++;
		}
		for (int i = 0; i < 8; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}