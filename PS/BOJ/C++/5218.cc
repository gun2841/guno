#include <iostream>
#include <string>
using namespace::std;
int solve(char a, char b)
{
	if (b >= a)
		return b - a;
	else
		return (b + 26 - a);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++)
		{
			cout << solve(a[i], b[i]) << " ";
		}
		cout << endl;
	}
}
