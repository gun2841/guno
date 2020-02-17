#include <iostream>
#include <string>
using namespace::std;
int main()
{
	string str1, str2;
	cin>> str1;
	cin >>str2;
	int loca = str1.find(str2);
	if ( loca >=0)
		printf("go");
	else
		printf("no");
}