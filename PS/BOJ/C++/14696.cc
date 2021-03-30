#include <iostream>

using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[5] = { 0,0,0,0,0 } ,brr[5] = { 0,0,0,0,0 };
	int N,a,b,d;
	cin >> N;

	for(int cn = 0;cn<N;cn++){
		cin >> a;
		while (a--)
		{
			cin >> d;
			arr[d]++;

		}
		cin >> b;
		while (b--)
		{
			cin >> d;
			brr[d]++;
		}

		if (arr[4] > brr[4])
			cout << "A";
		else if (arr[4] < brr[4])
			cout << "B";
		else
		{
			if (arr[3] > brr[3])
				cout << "A";
			else if (arr[3] < brr[3])
				cout << "B";
			else
			{
				if (arr[2] > brr[2])
					cout << "A";
				else if (arr[2] < brr[2])
					cout << "B";
				else
				{
					if (arr[1] > brr[1])
						cout << "A";
					else if (arr[1] < brr[1])
						cout << "B";
					else
					{
						cout << "D";
					}
				}
			}
		}
		cout << endl;
		for (int i = 1; i < 5; i++)
		{ 
			arr[i] = 0;
			brr[i] = 0;
		}
	}
}