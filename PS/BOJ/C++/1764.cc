#include <iostream>
#include <map>
#include <string>
using namespace::std;

int main()
{
	map<string, int> m;
	int a, b,cnt=0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		string str;
		cin >> str;
		m[str] = 1;
	}
	for (int i = 0; i < b; i++)
	{
		string str;
		cin >> str;
		if (m.count(str)) {
			m[str]++;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for (auto p : m) {
		if(p.second == 2)
		cout << p.first << endl;
	}
}