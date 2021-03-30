#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> comple;
	string str;
	getline(cin, str);
	while (str != "END")
	{
		reverse(str.begin(), str.end());
		comple.push_back(str);
		getline(cin, str);
	}
	for (int i = 0; i < comple.size(); i++)
	{
		cout << comple[i] << endl;
	}

}