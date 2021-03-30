#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	int N;
	unsigned long long file, cluster, ans=0;
	vector<unsigned long long> arr;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%llu", &file);
		arr.push_back(file);
	}
	scanf("%llu", &cluster);
	for (int i = 0; i < arr.size(); i++)
	{
		ans += arr[i] / cluster;
		if (arr[i] % cluster != 0)
			ans++;
	}
	cout << ans * cluster;
}
