#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;
	N = 1 + (pow(2, N));
	cout << N*N;
}