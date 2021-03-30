#include <iostream>
#include <set>
using namespace::std;

int main()
{
	set<int> a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a.insert(x);
	}
	
	for (auto i : a)
	{
		printf("%d ", i);
	}
}