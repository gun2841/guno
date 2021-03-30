#include <iostream>
#include <algorithm>
using namespace::std;
int arr[10000];
int cnt = 0;
bool ch(int arr[10000])
{
	for (int i = 0; i < cnt / 2; i++){
		if (arr[i] != arr[cnt - i - 1]){
			return false;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a;
		bool check = false;
		scanf("%d", &a);
		for (int i = 2; i <= 64; i++)
		{
			cnt = 0;
			fill(arr, arr + 10000, 0);
			int num = a;
			while (num != 0)
			{
				arr[cnt++] = num%i;
				num /= i;
			}
			check = ch(arr);
			if (check)
				break;
		}
		if (check) printf("1\n");
		else printf("0\n");
	}
}


