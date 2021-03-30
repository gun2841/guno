#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace::std;
int main()
{
	int i = 0;
	string str;
	getline(cin, str, '\n');
	string token;
	stringstream stream(str);
	while (stream >> token)
	{
		i++;
	}
	printf("%d", i);
}