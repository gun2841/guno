#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace::std;

int main()
{
	int arr[9];
	int sum = 0;
	bool check = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i <= 8; i++)
		for (int j = i + 1; j < 9; j++)
		{
			if (((sum - arr[i]) - arr[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					printf("%d\n", arr[k]);
					check = true;
				}

				break;
			}
			if (check)
				break;
		}
}