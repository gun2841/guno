#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		 int a = (y - x) * 2;
		 for (int i = 0;; i++)
		 {
			 if (i*(i + 1)*z >= a)
			 {
				 cout << i << endl;
				 break;
			 }
		}
		}

}