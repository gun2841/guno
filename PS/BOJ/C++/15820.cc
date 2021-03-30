#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	int state = 0;
	int s1, s2, ans, miny;

	cin >> s1 >> s2;
	for (int i = 0; i < s1; i++)
	{
		cin >> ans >> miny;
		if (ans != miny)
		{
			cout << "Wrong Answer";
			return 0;
		}
	}
	for (int i = 0; i < s2; i++)
	{
		cin >> ans >> miny;
		if (ans != miny) {
			cout << "Why Wrong!!!";
			return 0;
		}
	}
	
		cout << "Accepted";

}