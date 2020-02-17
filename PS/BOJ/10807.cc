#include <iostream>
#include <map>
using namespace::std;
int main()
{
	map <int, int> V;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a;
		scanf("%d", &a);
		V[a]++;
	}
	scanf("%d", &n);
	cout << V[n];
}