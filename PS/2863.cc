#include <iostream>
using namespace::std;

int main()
{
	int A, B, C, D, temp , swap;
	float ans, max = 0;
	cin >> A >> B >> C >> D;
	for (int i = 0; i < 4; i++){
		ans = (float)A / (float)C + (float)B / (float)D;
		swap = A;
		A = C;
		C = D;
		D = B;
		B = swap;
		if (max < ans)
		{
			temp = i;
			max = ans;
		}
	}
	cout << temp;
}