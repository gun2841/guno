#include <iostream>
#include <algorithm>
using namespace::std;
int main()
{
	int hp, mp, atk, def, a ,b,c,d;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &atk, &def, &a, &b, &c, &d);
		hp += a;
		mp += b;
		atk += c;
		def += d;
		if (hp < 1)
			hp = 1;
		if (mp < 1)
			mp = 1;
		if (atk < 0)
			atk = 0;
		printf("%d\n", hp + mp * 5 + atk * 2 + def * 2);
	}
}