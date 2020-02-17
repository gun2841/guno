#include <iostream>
#include <string>
#include <cmath>
#include<vector>
#include <algorithm>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	int a =0, b=1, c=1;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;
		vector<int> arr;
		arr.push_back(a); arr.push_back(b); arr.push_back(c);
		sort(arr.begin(), arr.end());

		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}