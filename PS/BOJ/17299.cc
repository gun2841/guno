#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
#include <stack>
using namespace::std;
int vt[1000001];
int ans[1000001];
int visit[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i];
		ans[i] = -1;
		visit[vt[i]]++;
	}
	
	stack<pair<int,int>> st;
	st.push({ visit[vt[n-1]],vt[n - 1] });

	for (int i = n - 2; i >= 0; i--)
	{
		while (!st.empty() && visit[vt[i]]>=st.top().first)
		{
				st.pop();
		}
		ans[i] = st.empty() ? -1 : st.top().second;
		st.push({ visit[vt[i]],vt[i] });
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}