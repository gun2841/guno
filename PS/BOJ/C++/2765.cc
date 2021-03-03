#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main() {
	for (int i = 1;; i++)
	{
		float dis, MPH,rad,seconds;
		int  clock;
		scanf("%f %d %f", &rad, &clock, &seconds);
		dis = (float)rad*M_PI*((float)clock) / 63360;
		MPH = dis / seconds * 3600;

		if (clock == 0)
			break;
		printf("Trip #%d: %.2f %.2f\n", i, dis, MPH);
	}
}
