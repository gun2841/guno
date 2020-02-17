#include <iostream>
#include <vector>
using namespace::std;
bool check[5000001];
int main()
{
	vector<long long int> arr;
	long long int max, min;
	scanf("%lld %lld", &min, &max);
	for (long long int i = 2;; i++)
	{
		if (i*i > max) break;
		arr.push_back(i*i);
	}
	long long int ans=0;
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		for (long long int j = (min / arr[i])*arr[i]; j <= max; j += arr[i])
		{
			if (j - min < 0)
				continue;
			if (check[j - min] == 0)
			{
				check[j - min] = 1;
				ans++;
			}
		}
	}
	cout << max - min - ans + 1;
	return 0;

}
