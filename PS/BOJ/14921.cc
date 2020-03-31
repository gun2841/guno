#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace::std;
#define ull unsigned long long
int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> vt;
	deque<int> mvt;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t; cin >> t;
		if (t >= 0)
			vt.push_back(t);
		else
			mvt.push_front(t);
	}
	int m=999999999;
	if (vt.size() > 1)
		m = vt[0] + vt[1];
	if (mvt.size() > 1)
	{
		int temp = mvt[0] + mvt[1];
		if (abs(m) > abs(temp))
			m = temp;
		
	}
	for(int i = 0 ;i<vt.size();i++)
		for (int j = 0; j < mvt.size(); j++)
		{
			int temp = vt[i] + mvt[j];
			if (temp == 0)
			{
				cout << "0";
				return 0;
			}
			else if(abs(m) > abs(temp)){
				m = temp;
			}
		}
	cout << m;
}