#include <iostream>

using namespace::std;

int main()
{
	int arr[9];
	int state = 0;

	for (int i = 1; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		if (state == 0) {
			if (arr[i] == 1)
				state = 1;
			else if (arr[i] == 8)
				state = 2;
		}
		else {
			if (arr[i] == i && state == 1)
				state = 1;
			else if (arr[i] == (9 - i) && state == 2)
				state = 2;
			else
				state = 3;
		}
	}
	if (state == 1)
		printf("ascending");
	else if (state == 2)
		printf("descending");
	else
		printf("mixed");
}