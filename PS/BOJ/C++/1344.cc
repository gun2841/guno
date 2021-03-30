#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace::std;
bool prime(int n);
double start(int count, int a, int b);
double arr[22][22][22] = {{{-1}}};
double A, B;
int main(void)
{
	cin >> A >> B;
	A /= 100;
	B /= 100;
	memset(arr, -1, sizeof(arr));
	printf("%0.12f", start(0, 0, 0));
	return 0;
}
bool prime(int n)
{
	int arr[7] = { 2,3,5,7,11,13,17 };
	for (int i = 0; i < 7; i++)
		if (n == arr[i])
			return true;

	return false;
}
double start(int count, int a, int b)
{
	if (count == 18) return (prime(a) || prime(b));

	double& temp = arr[count][a][b];

	if (temp > -0.5) return temp;

	temp = 0;

	temp += A*(1 - B)*start(count + 1, a + 1, b);
	temp += (1 - A)*B*start(count + 1, a, b + 1);
	temp += (1 - A)*(1 - B)*start(count + 1, a, b);
	temp += A*B*start(count + 1, a + 1, b + 1);
	return temp;
}