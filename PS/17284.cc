#include <iostream>
#include <string>

using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	string str;
	getline(cin, str);
	int cost = 5000;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
			cost -= 500;
		else if (str[i] == '2')
			cost -= 800;
		else if (str[i] == '3')
			cost -= 1000;
	}
	cout << cost;
}