#include <iostream>
using namespace::std;
int main()
{
	//ios_base::sync_with_stdio(false);
	int c;
	float g;
	int t,n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int c_ = 0;
		float avg = 0.0;
		for (int i = 0; i < n; i++)
		{
			cin >> c >> g;
			c_ += c;
			avg += (g*c);
		}
		cout << c_ << " ";

		printf("%.1f\n", (float)avg/(float)c_);

	}
}
