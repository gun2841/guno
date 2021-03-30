#include <iostream>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	ull R, L, mul = 2;
	cin >> L >> R;
	ull ans = 0;
	
	while (1)
	{
		L = L * R / 100;
		if (L <= 5)
			break;
		
		ans += (L*mul);
		mul *= 2;
	}
	cout << ans;
}