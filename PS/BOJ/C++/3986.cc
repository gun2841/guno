#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;
int arr[100001];
int main() {
	//ios_base::sync_with_stdio(false);
	
	int T,ans=0; cin >> T;
	for (int i = 0; i < T; i++)
	{
		stack<char> st;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
		
			if (st.empty())
			{
				st.push(str[j]);
			}
			else {
				if (st.top() == str[j]) {
					st.pop();
				}
				else {
					st.push(str[j]);
				}
			}
		}
		if (st.empty())
			ans++;
	}
	cout << ans;
}