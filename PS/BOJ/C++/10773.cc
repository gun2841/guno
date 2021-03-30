#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define ull unsigned long long
int main(int argc, char** argv)
{
	stack<int> st;
	int K,ans =0;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a; cin >> a;
		if (a == 0)
		{
			ans -= st.top();
			st.pop();
		}
		else
		{
			ans += a;
			st.push(a);
		}
	}
	cout << ans;
}