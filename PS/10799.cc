#include <iostream>
#include <stack>
#include <string>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	stack<int> st;
	cin >> a;
	int ans = 0;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		if(a[i] == '(') {
			st.push(i);
		} else {
			if(st.top() + 1 == i) {
				st.pop();
				ans += st.size();
			} else {
				st.pop();
				ans += 1;
			}
		}
	}
	cout << ans;
}