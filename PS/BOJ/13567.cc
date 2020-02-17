#include <iostream>
#include <string>
using namespace::std;
int a = 0, b = 0;
void move_(int dir, int d)
{
	if (dir == 1) { b += d; }
	else if (dir == 2) { a += d; }
	else if (dir == 3) { b -= d; }
	else if (dir == 4) { a -= d; }
}
int TURN(int dir, int d)
{
	if (d == 1) {
		dir += 1;
		if (dir > 4)
			dir -= 4;
	}
	else if (d == 0) {
		dir -= 1;
		if (dir < 1)
			dir += 4;
	}

	return dir;
}
int main()
{
	int n, m,dir =2;
	bool checker = true;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		string cmd;
		int d;
		cin >> cmd >> d;
		if(cmd == "MOVE")
		{
			move_(dir, d);
		}
		else if (cmd == "TURN")
		{
			dir = TURN(dir, d);
		}

		if (a > m || b > m || a < 0 || b < 0)
			checker = false;
	}
	if (checker)
	{
		cout << a << " " << b;
	}
	else
		cout << "-1";
	//system("pause");
}
