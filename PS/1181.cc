#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace::std;
int main()
{
	vector<string> v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), [](string u, string v) {
		if (u.size() == v.size()) {
			return u < v;
		}
		else {
			return u.size() < v.size();
		}
	});
	auto a = unique(v.begin(), v.end());
	v.erase(a, v.end());
	for (string st : v)
	{
		cout << st << endl;
	}
}