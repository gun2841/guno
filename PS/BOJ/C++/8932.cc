#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int t_score(float A,float B,float C,float P)
{
	return A * powf((B - P), C);
}
int f_score(float A, float B, float C, float P)
{
	return A * powf((P - B), C);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int Testcase;
	float arr[7];
	cin >> Testcase;
	while (Testcase--)
	{
		for (int i = 0; i < 7; i++)
			cin >> arr[i];
		cout << t_score(9.23076, 26.7, 1.835, arr[0]) +
			f_score(1.84523, 75, 1.348, arr[1]) +
			f_score(56.0211, 1.5, 1.05, arr[2]) +
			t_score(4.99087, 42.5, 1.81, arr[3]) +
			f_score(0.188807, 210, 1.41, arr[4]) +
			f_score(15.9803, 3.8, 1.04, arr[5]) +
			t_score(0.11193, 254, 1.88, arr[6]) << endl;
	}
}