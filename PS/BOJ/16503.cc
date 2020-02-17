#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int cal(int a, char oper, int b)
{
	switch (oper)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		break;
	}
}
int main() {
	int a, b, c;
	char oper1, oper2;
	scanf("%d %c %d %c %d", &a, &oper1, &b, &oper2, &c);
	int first = cal(cal(a, oper1, b),oper2,c);
	int second = cal(a,oper1,cal(b, oper2, c));
	if (first < second)
	{
		printf("%d\n", first);
		printf("%d", second);
	}
	else
	{
		printf("%d\n", second);
		printf("%d", first);
	}
}