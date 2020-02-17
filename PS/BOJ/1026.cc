#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	unsigned long long  A[50], B[50];
	unsigned long long S=0;
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < cnt; i++)
	{
		cin >> B[i];
	}
	
	sort(A, A + cnt);
	sort(B, B + cnt);

	for (int i = 0; i < cnt; i++)
	{
		S = S+A[i] * B[cnt - i-1];
	}
	cout << S;
}