#include <stdio.h>
#include <cstdlib>
double solve(char *s)
{
	double mass = 0;
	double ret = 0;
	while (*s != 0)
	{
		if (*s >= 48 && *s <= 57)    
		{
			ret += mass * atof(s);  
			while (*s >= 48 && *s <= 57) s++;      
			mass = 0;             
			continue;
		}
		ret += mass; 
		if (*s == 'C') mass = 12.010;    
		if (*s == 'H') mass = 1.008;
		if (*s == 'O') mass = 16.00;
		if (*s == 'N') mass = 14.01;
		s++;
	}
	ret += mass;         
	return ret;
}
int main()
{
	int Test;
	char str[81];
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%s", str);
		printf("%.3f\n", solve(str));
	}
}