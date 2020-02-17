#include <iostream>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int A,B,C;
	cin >> A >> B;
	cin >> C;
	int total = A * 60 + B;

	total += C;
	if (total >= 1440)
		total -= 1440;
	cout << total / 60 << " " << total % 60;
}