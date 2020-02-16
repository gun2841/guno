#include <iostream>
using namespace::std;
int N;
char arr[26][3];
void pre(char a)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == a)
		{
			printf("%c",a);
			if (arr[i][1] != '.') pre(arr[i][1]);
			if (arr[i][2] != '.') pre(arr[i][2]);
		}
	}
}
void mid(char a)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == a)
		{
			if (arr[i][1] != '.') mid(arr[i][1]);
			printf("%c", a);
			if (arr[i][2] != '.') mid(arr[i][2]);
		}
	}
}
void aft(char a)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == a)
		{
			if (arr[i][1] != '.') aft(arr[i][1]);
			if (arr[i][2] != '.') aft(arr[i][2]);
			printf("%c", a);
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	pre('A');
	cout << endl;
	mid('A');
	cout << endl;
	aft('A');

}


