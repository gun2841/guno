#include <iostream>
using namespace::std;

int main()
{
	int R, B;
	scanf("%d %d", &R, &B);

	for (int L = R+B;; L --)
	{
		int W;
		if (((R+B) %L) == 0)
		{
			W = (R+B) / L;

			if (((L - 2) *(W - 2)) == B)
			{
				printf("%d %d", L, W);
				return 1;
			}
		}
	}
}