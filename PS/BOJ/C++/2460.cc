#include <iostream>
using namespace std;
int main() {
	int in, out;
	int total = 0,max =0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &out, &in);
		total = total + in - out;
		if (max < total)
			max = total;
	}
	printf("%d", max);
}
