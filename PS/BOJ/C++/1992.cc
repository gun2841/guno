#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace::std;
int n;
int arr[65][65];
void quad(int x, int y, int size)
{
	if (size == 1) {
		cout << arr[x][y]; return;
	}
	int cur = arr[x][y];
	bool num[2] = { true,true };
	for (int i = x; (i < x + size)  ; i++)
		for (int j = y; (j < y + size); j++)
		{
			if (arr[i][j]) num[0] = false;
			else num[1] = false;
		}

	if (num[0]) cout << 0;
	else if (num[1]) cout << 1;
	else {
		cout << "(";
		quad(x, y, size / 2);
		quad(x, y + size / 2, size / 2);
		quad(x + size / 2, y, size / 2);

		quad(x + size / 2, y + size / 2, size / 2);
		cout << ")";
	}
}

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0; j < n;j++)
			scanf("%1d", &arr[i][j]);

	quad(0, 0, n);

}
