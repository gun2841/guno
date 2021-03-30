#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main() {
	string str;
	cin >> str;

	for (int i = 0; i <= str.size(); i++)
	{
		arr[(int)str[i]-48]++;
	}
	arr[6] = (arr[6] + arr[9]+1)/2;
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max;
}
