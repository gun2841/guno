#include <iostream>
#include <string>
using namespace::std;
int arr[26];
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);
}