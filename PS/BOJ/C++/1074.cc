#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace::std;
int tx=0, ty=0;
int find(int x, int y,int len)
{
	if (x >= tx && x < tx+len && y >= ty && y < ty+len)
		return 0;
	if (x >= tx + len && x< tx + 2 * len &&  y >= ty && y <ty+ len)
		return 2;
	if (x >= tx && x < tx+len && y >= ty + len && y < ty + 2 * len)
		return 1;
	if (x >= tx + len && x<tx+ 2 * len && y >= ty + len && y <ty+ 2 * len)
		return 3;
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, r, c;
	cin >> n >> r >> c;
	int len = pow(2, n-1);
	int ans = 0;
	while (n--)
	{
		int loc = find(r, c, len);
		ans += (pow(4,n) * loc);
		if (loc == 0) { tx += 0;ty += 0; }
		else if (loc == 1) { ty += (len); }
		else if (loc == 2) { tx += (len); }
		else if (loc == 3) { tx += (len), ty += (len);		}
		len /= 2;
	}
	cout << ans;
}