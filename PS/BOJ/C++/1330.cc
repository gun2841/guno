#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ull unsigned long long

int main(int argc, char** argv)
{
	int A, B;
	cin >> A >> B;
	if (A > B)
		cout << ">";
	else if (A < B)
		cout << "<";
	else cout << "==";
}