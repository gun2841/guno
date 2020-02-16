#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ull unsigned long long
vector<ull> vt;

int main(int argc, char** argv)
{
	ull a = 1;
	for (int i = 0; i < 41; i++)
	{
		if (a > 9223372036854775807) {
			break;
		}
		vt.push_back(a);
		a *= 3;
	}
	ull n;
	cin >> n;
	if (n == 0) {
		cout << "NO";
		return 0;
	}
	for (int i = 40; i >= 0; i--)
	{
		if (n >= vt[i])
		{
			//cout << vt[i] << endl;
			n -= vt[i];
		}
	}
	if (n == 0)
		cout << "YES";
	else
		cout << "NO";
}