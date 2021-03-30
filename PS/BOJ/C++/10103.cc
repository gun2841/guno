#include <iostream>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, ans_a=0,ans_b=0;
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			ans_b -= a;
		else if (a < b)
			ans_a -= b;
	}
	cout << 100 + ans_a << endl;
	cout << 100 + ans_b;
}
