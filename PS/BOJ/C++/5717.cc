#include <iostream>
using namespace::std;
int main()
{
	int M, F;
	int count = 0;
	while(1){
		scanf("%d %d", &M, &F);
		if (M == 0 && F == 0)
			break;
		printf("%d\n", count = M+F);
	} 
}
