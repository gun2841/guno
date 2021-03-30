#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace::std;
int main()
{
	int N,cnt = 0; cin >> N;
	while (N != 0)
	{
		for (int i = 1;; i++)
		{
			if (N - i >= 0)
			{
				
				cnt++;
				N -= i;
			}
			else {
				break;
			}
		}
	}
	cout << cnt;
}