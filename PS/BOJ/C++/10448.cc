#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace::std;
int arr[3100];
int main()
{
	vector<int> vt;
	for (int i = 1; i < 45; i++) {
		int a = i * (i + 1) / 2;
		vt.push_back(a);
	}

	for (int i = 0; i < vt.size(); i++)
		for (int j = 0; j < vt.size(); j++)
			for (int k = 0; k < vt.size(); k++)
				arr[vt[i] + vt[j] + vt[k]] = 1;
				
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		if (arr[d] == 1)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

}