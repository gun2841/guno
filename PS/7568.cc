#include <iostream>
using namespace::std;
int str[50][3];
int main()
{
	ios_base::sync_with_stdio(false);
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		str[i][0] = x;
		str[i][1] = y;
	}
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (str[i][0] > str[j][0] && str[i][1] > str[j][1])
				str[j][2]++;
			else if (str[i][0] < str[j][0] && str[i][1] < str[j][1])
				str[i][2]++;
		}
	}
	for (int i = 0; i < N; i++)
		cout << str[i][2]+1 << " ";
}