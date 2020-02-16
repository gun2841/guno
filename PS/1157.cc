#include <iostream>
using namespace::std;

int main()
{
	int a[26] = { 0 };
	int b;
	int c,d=0;
	while (1)
	{
		b = getchar();
		if (b < 65)
			break;
		if (b < 97) b += 32;
		a[b - 97]++;
	}
	for (int i = 0; i < 26; i++){
		if (d < a[i]){
			d = a[i];
			c = i;
		}
	}
	for (int i = 0; i<26; i++){ 
		if (d == a[i] && i != c){
			putchar('?');
			return 0;
		}
	}
	printf("%c", c + 65);
}

