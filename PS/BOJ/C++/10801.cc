#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace::std;
int main()
{
	//ios_base::sync_with_stdio(false);
	int A[10], B[10], cnt_a =0,cnt_b=0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d",& A[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
			cnt_a++;
		else if (B[i] > A[i])
			cnt_b++;
	}
	if (cnt_a > cnt_b)
		printf("A");
	else if (cnt_b > cnt_a)
		printf("B");
	else
		printf("D");
}
