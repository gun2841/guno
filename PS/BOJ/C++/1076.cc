#include <iostream>
#include <string>
#include <math.h>
using namespace::std;
struct resistance{
	string str;
	long long value;
	long long mul;
};
int main()
{
	struct resistance rs[10];
	rs[0].str = "black";
	rs[1].str = "brown";
	rs[2].str = "red";
	rs[3].str = "orange";
	rs[4].str = "yellow";
	rs[5].str = "green";
	rs[6].str = "blue";
	rs[7].str = "violet";
	rs[8].str = "grey";
	rs[9].str = "white";
	for (int i = 0; i < 10; i++){
		rs[i].value = i;
		rs[i].mul = pow(10, i);
	}
	string str[3];
	cin >> str[0];
	cin >> str[1];
	cin >> str[2];

	long long a;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++)
		{
			if (i == 0)
			{
				if (rs[j].str == str[0])
				{
					a = rs[j].value *10;
					break;
				}
			}
			else if ( i == 1)
			{
				if (rs[j].str == str[1])
				{
					a += rs[j].value;
					break;
				}
			}
			else {
				if (rs[j].str == str[2])
				{
					a *= rs[j].mul;
					break;
				}
			}
		}
	}
	cout << a;
}