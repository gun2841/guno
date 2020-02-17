#include <iostream>
using namespace::std;

int main()
{
	int burger[3], soda[2];
	int min_1=2000, min_2=2000;
	for (int i = 0; i < 3; i++){
		scanf("%d", burger + i);
		if (burger[i] < min_1)
			min_1 = burger[i];
	}
	for (int i = 0; i < 2; i++){
		scanf("%d", soda + i);
		if (soda[i] < min_2)
			min_2 = soda[i];
	}
	cout << min_1 + min_2 - 50;
}