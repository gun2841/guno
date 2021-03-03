#include <iostream>
#include <math.h>
using namespace::std;
int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int ans = ceil((double(V - A) / double(A - B))) + 1;
	cout << ans;
}