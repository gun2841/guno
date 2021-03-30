#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> vt;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vt.push_back(a);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e, sum = 0;
		cin >> s >> e;
		for (int c = s; c <= e; c++)
			sum += vt[c];
		cout << sum << endl;
	}
}