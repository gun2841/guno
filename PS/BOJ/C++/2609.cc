#include <iostream>
#include <stack>
#include <string>
using namespace::std;
int gcd(int a, int b);
int main()
{
	int a, b;
	cin >> a>> b;
	int g = gcd(a, b);
	cout << g << endl;
	cout << a * b / g;

}
int gcd(int a, int b)
{
	return (a%b == 0 ? b : gcd(b, a%b));
}