#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
using namespace::std;


int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string number;
		cin >> number;
		deque<int> dq;
		string num="";
		for (int i = 0;i < number.size();i++)
		{
			if (isdigit(number[i])) {
				num += number[i];
			}
			else if(number[i] == ']' || number[i] == ','){
				if (n != 0) {
					dq.push_back(atoi(num.c_str()));
				}
				n--;
				num.clear();
			}
		}
		bool state = true, err = false;
		for (int i = 0;i < cmd.size();i++)
		{
			if (cmd[i] == 'D')
			{
				if (dq.empty())
				{
					err = true; break;
				}
				if (state) {  dq.pop_front(); }
				else {  dq.pop_back(); }
			}
			else if (cmd[i] == 'R')
			{
				state = !state;
			}

		}
		if (err) {
			cout << "error\n";
			continue;
		}
		cout << "[";
		while (!dq.empty())
		{
			if (state) {
				cout << dq.front();
				if (dq.size() != 1)
					cout << ",";
				dq.pop_front();
			}
			else
			{
				cout << dq.back();
				if (dq.size() != 1)
					cout << ",";
				dq.pop_back();

			}
		}
		cout << "]\n";
	}
}
