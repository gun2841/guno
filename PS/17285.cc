#include <iostream>
#include <string>

using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	string str;
	cin >> str;
	int key = str[0] ^ 'C';
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = str[i] ^ key;
	}
	cout << str;
}