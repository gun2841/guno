#include <iostream>
#include <string>
using namespace::std;
int main(){
	string str[52];
	char temp[52];
	int n;
	int size;
	cin >> n;
	cin >> str[0];
	size = str->size();
	for (int i = 0; i < size; i++)
	{
		temp[i] = str[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < size; j++)
		{
			
			if (temp[j] == str[i][j])
				continue;
			else
				temp[j] = '?';
		}
	}
	for (int i = 0; i < size; i++)
		cout << temp[i];
}
