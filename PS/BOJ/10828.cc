#include <iostream>
#include <stack>
#include <string>
using namespace::std;

int main()
{
	stack<int> st;
	string str;
	int N;
	cin >> N;
	cin.ignore();

	while (N--)
	{
		cin >> str;

		if (str.compare(0, 4, "push") == 0) {
			int n;
			cin >> n;
			st.push(n);
		}
		else if (str.compare("pop") == 0) {
			if (st.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (str.compare("size") == 0) {
			cout << st.size() << endl;
		}
		else if (str.compare("empty") == 0) {
			if (st.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (str.compare("top") == 0)
		{
			if (st.empty()) cout << "-1" << endl;
			else cout << st.top() << endl;
		}
	}
}