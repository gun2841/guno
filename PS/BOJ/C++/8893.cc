#include <stdio.h>
#include <string.h>

enum DIRECTION { LEFT, UP, RIGHT, DOWN };

char s[100002];

int get_monotone()
{
	int len = strlen(s), i, flag=0, angle = LEFT, x_axis=1, y_axis=1;

	s[len] = s[0];
	for(i=0; i<=len; i++)
	{
		switch(s[i])
		{
			case 'R':
				angle = (angle + 1) % 4;
				
				if(flag == 1)
				{
					if(angle == LEFT || angle == RIGHT)
						x_axis = 0;
					if(angle == UP || angle == DOWN)
						y_axis = 0;
				}

				flag = 1;
				break;
			case 'L':
				if(--angle < 0)
					angle = DOWN;

				flag = 0;
		}
	}

	return x_axis + y_axis;
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%s", &s);
		printf("%d\n", get_monotone());
	}
}