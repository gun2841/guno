#include <iostream>
#include <string>
using namespace::std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		int num;
		string str;
		scanf("%d", &num);
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < num; j++)
				printf("%c", str[i]);
		}
		printf("\n"); 
	}
}

