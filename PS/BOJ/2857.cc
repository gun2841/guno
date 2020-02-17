#include <iostream>
#include <string>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[6] = { 0 };
	bool check = false;
	string s;
	for (int i = 1; i < 6; i++)
	{
		cin >> s;
		if (s.find("FBI") != string::npos)
		{
			check = true;
			arr[i] = i;
		}
	}
	if (check == false)
	{
		cout << "HE GOT AWAY!";
	}
	else
	{
		for (int i = 1; i < 6; i++)
		{
			if(arr[i] != NULL)
			cout << arr[i] << " ";
		}
	}
}