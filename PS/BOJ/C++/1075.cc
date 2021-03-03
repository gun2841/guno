#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace::std;

int main()
{
	string N;
	char ch[3];
	int F, _N;
	cin >> N;
	cin >> F;
	N[N.size() - 2] = '0';
	N[N.size() - 1] = '0';
	_N = atoi(N.c_str());

	while (_N%F != 0)
	{
		_N++;
	}
	_N %= 100;
	if (_N < 10)
	{
		sprintf(ch, "%d", _N);
		ch[2] = NULL;
		ch[1] = ch[0];
		ch[0] = '0';

		cout << ch;
	}
	else{
		N = to_string(_N);
		cout << N;
	}
}