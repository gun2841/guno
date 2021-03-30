#include <iostream>
using namespace::std;
void solve(int a, int b, int c)
{
	if (a == 60 && b == 60 && c == 60)
		cout << "Equilateral";
	else if ((a + b + c) == 180 && (a == b || b == c || c == a))
		cout << "Isosceles";
	else if ((a + b + c) == 180)
		cout << "Scalene";
	else
		cout << "Error";
		 
}
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	solve(a, b, c);

}
