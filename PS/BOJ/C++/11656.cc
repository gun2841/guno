#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	vector<string> v;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		v.push_back(str.substr(i,str.size()));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}