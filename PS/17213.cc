#include <iostream>
#include <string>
#include <stack>
#include <bitset>
using namespace::std;
int N, ans = 0;
void jagu(int n ,int M)
{
	if (n == N)
	{
		ans++;
		return;
	}
	for (int i = 1; i < M; i++)
	{
		jagu(n + 1, M - i);
	}
}
int main()
{
	int M;
	cin >> N >> M;
	jagu(1, M);
	cout << ans;
}

