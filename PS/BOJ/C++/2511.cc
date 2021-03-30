#include <iostream>
using namespace::std;

int main()
{
	ios_base::sync_with_stdio(false);
	int A[11], B[11], win_a = 0, win_b = 0;
	char recent_win = 'd';
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
		{
			win_a += 3;
			recent_win = 'a';
		}
		else if (A[i] < B[i])
		{
			win_b += 3;
			recent_win = 'b';
		}
		else {
			win_a += 1; win_b += 1;
		}
	}
	cout << win_a << " " << win_b << endl;
	if (win_a > win_b)
		cout << "A";
	else if (win_a < win_b)
		cout << "B";
	else {
		switch (recent_win)
		{
		case 'a':
			cout << "A";
			break;
		case 'b':
			cout << "B";
			break;
		case 'd':
			cout << "D";
			break;
		}
	}
}