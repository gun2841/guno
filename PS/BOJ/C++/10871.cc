#include <iostream>
#include <vector>
using namespace::std;
int main(void)
{
	int N, x ,a;
	vector<int> arr;
	cin >> N >> x;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		if (a < x)
			arr.push_back(a);
	}
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}