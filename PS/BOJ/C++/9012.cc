#include <iostream>
#include <climits>
#include <string>
using namespace::std;

int main()
{
	int N;
	cin >> N;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	while (N--)
	{
		string str;
		int count = 0, check = 0;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '('){
				count++;
				check = 1;
			}
			if (str[i] == ')'  && check == 1){
				count--;
				if (count == 0)
					check = 0;
			}
			else if (check == 0)
				count += 100;
			
		}
		if (count == 0 && str[0] != ')')
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	
	}
}