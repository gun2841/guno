#include <iostream>
using namespace::std;
int main()
{
	int T;
	scanf("%d", &T);
	int temp = T + 1;
	while (temp--){
		char ch='a';
		int sum = 0, count = 1;
		do{
			scanf("%c", &ch);
			if (ch == 'O'){
				sum += count;
				count = count + 1;
			}
			else
				count = 1;
		} while (ch != '\n');
		if (temp != T)
		printf("%d\n", sum);
	}
}

