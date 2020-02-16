
#include <iostream>
using namespace::std;
int main() {
	int num;
	cin >> num;
	for (int i = 0; i <num; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << "1" << endl;
		if (a % 2 == 0)
		{
			for (int i = 0; i < a; i++) {
				for (int j = 0; j <b; ++j)
				{
					if (i % 2 == 0)
						printf("(%d,%d)\n", i, j);
					else
						printf("(%d,%d)\n", i, b - 1 - j);
				}
			}
		}
		else
		{
			for (int i = 0; i < b; i++) {
				for (int j = 1; j < a; j++)
				{
					if(i%2 ==0)
						printf("(%d,%d)\n", j, i);
					else
						printf("(%d,%d)\n", a - j, i);
				}
			}
			for (int i = b - 1; i >= 0; i--)
						 printf("(0,%d)\n",i);
		}

	}
}
