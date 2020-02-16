#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int d;
		cin >> d;
		cout << (int)sqrt(d - int(sqrt(d)))<<endl;
	}
}