#include <iostream>
using namespace::std;
int main()
{
	int a, test =3;
	while (test--) {
		int count=0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &a);
			if (a == 0)
				count++;
		}
		switch (count)
		{
		case 1:
			printf("A");
			break;
		case 2:
			printf("B");
			break;
		case 3:
			printf("C");
			break;
		case 4:
			printf("D");
			break;
		default:
			printf("E");
		}
		printf("\n");
	}
}