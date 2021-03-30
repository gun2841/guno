#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
#define Pi 3.14159265359
int main()
{
	ios_base::sync_with_stdio(false);
	double R;
	cin >> R;
	cout.precision(6);
	cout.setf(ios::fixed);
	cout << R * R*Pi<< endl;
	cout << R * R*2;
}