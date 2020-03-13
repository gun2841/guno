#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
vector<int> solution(vector<int> prices) {
	int n = prices.size();
	vector<int> answer(n);
	stack<P> st;
	for (int i = 0; i < n; i++)
	{
		if (st.empty() == true)
		{
			st.push(P(prices[i], i));
		}
		else
		{
			if (st.top().first <= prices[i])
			{
				st.push(P(prices[i], i));
			}
			else
			{
				while (1)
				{
					answer[st.top().second] = (i-st.top().second);
					st.pop();
					if (st.empty() || st.top().first <= prices[i])
						break;
				}
				st.push(P(prices[i], i));
			}
		}
	}
	while (!st.empty())
	{
		answer[st.top().second] = (n - st.top().second-1);
		st.pop();
	}
	return answer;
}