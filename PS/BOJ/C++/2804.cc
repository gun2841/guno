#include <iostream>
#include <string>
using namespace::std;
int a, b;
int n, m;
void compare_str(string str_a, string str_b)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str_a[i] == str_b[j]) {
				a = i; b = j;
				return;
			}			
		}
	}
}
int main()
{
	string A, B;
	cin >> A>>  B;
	n = A.size();
	m = B.size();
	compare_str(A, B);

	for (int i = 0; i < m; i++)
	{
		if (i == b)
		{
			cout << A << endl;
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (a == j)
			{
				cout << B[i];
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
}