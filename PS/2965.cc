#include <iostream>
using namespace::std;
int sum = 0;
int a, b, c;
int Jump();
int main(void)
{
	
	
	cin >> a >> b >> c;

	while (1)
	{
		if (Jump() == -1)
			break;;
	}
	
	cout << sum<<endl;
	return 0;
}
int Jump()
{
	
	if (b - a == 1 && c - b == 1)
	{
		return -1;
	}

	if (b - a > c - b) {
		c = b - 1;
		swap(b, c);
		sum++;
		return 0;
	}
	else
	{
		a = b + 1;
		swap(a, b);
		sum++;
		return 0;
	}

	return -1;
}
