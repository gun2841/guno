#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
	// your code goes here
	int test;
	cin >> test;
	
	unsigned long long arr[101];
	unsigned long long a,temp;
	cin >> a;
	arr[0] = a;
	temp = a;
	for(int i =  1;i<=test;i++)
	{
		cin >> a;
		arr[i] = a*(i+1)-temp*i;
		temp =a;
	}
	for(int i =0;i<test;i++)
	cout << arr[i] <<" ";
	return 0;
}