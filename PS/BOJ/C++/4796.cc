#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
using namespace::std;
int arr[1001];
int main()
{
	int L, P, V, i = 1;
	while (scanf("%d %d %d", &L, &P, &V))
	{
		if (L == 0 && P == 0 && V == 0)
			return 0;
		int ans = 0;
		ans = V / P * L;
		if (V % P > L)
			ans += L;
		else
			ans += V % P;
		cout << "Case " << i++ << ": " << ans << endl;
	}

}	