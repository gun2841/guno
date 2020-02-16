#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
#define ull unsigned long long
int main()
{
	ios_base::sync_with_stdio(false);
	int s, t, d;
	cin >> s >> t >> d;
	cout << d / (s * 2)*t;
}