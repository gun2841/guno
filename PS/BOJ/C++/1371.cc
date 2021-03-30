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
#include <bitset>
#include <stack>
using namespace::std;

int alphabet[26];
int main()
{
	//ios_base::sync_with_stdio(false);
	char x;
	while ((x = getchar()) != EOF)
	{
		if (x >= 'a' && x <= 'z')
			alphabet[x - 'a']++;
	}

	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] > max)
		{
			max = alphabet[i];
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == max)
			printf("%c", i + 'a');
	}

}
