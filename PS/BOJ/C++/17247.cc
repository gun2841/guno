#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	bool check = true;
	int N, M,fx,fy,sx,sy;
	cin >> N >> M;
	for(int i = 0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			int t; cin >> t;
			if (t == 1 && check)
			{
				fx = i; fy = j;
				check = false;
			}
			else if (t == 1 && !check)
			{
				sx = i; sy = j;
			}
		}
	N = abs(fx - sx); M = abs(fy - sy);
	
	cout << N+M;
}