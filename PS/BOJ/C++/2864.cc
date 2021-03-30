#include <iostream>
#include <sstream>
using namespace::std;

int main()
{
	string arr, brr;
	int A, B, max ,min;
	scanf("%d %d", &A, &B);
	arr = to_string(A);
	brr = to_string(B);
	for (int i = 0; i < arr.length() ; i++) {
		if (arr[i] == '5')
			arr[i] = '6';
	}
	for (int i = 0; i<brr.length(); i++) {
		if (brr[i] == '5')
			brr[i] = '6';
	}
	max = atoi(arr.c_str()) + atoi(brr.c_str());
	for (int i = 0; i<arr.length(); i++) {
		if (arr[i] == '6')
			arr[i] = '5';
	}
	for (int i = 0; i<brr.length(); i++) {
		if (brr[i] == '6')
			brr[i] = '5';
	}
	min= atoi(arr.c_str()) + atoi(brr.c_str());
	printf("%d %d", min, max);

}
