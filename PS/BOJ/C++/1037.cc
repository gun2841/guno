#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

int main()
{
	int N;
	long long a, ans =1 ;
	vector<long long> vt;
	cin >> N;
	while (N--)
	{
		cin >> a;
		vt.push_back(a);
	}
	sort(vt.begin(), vt.end());

	cout << vt[0] * vt[vt.size()-1];
}