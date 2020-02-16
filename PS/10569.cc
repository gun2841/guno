#include <iostream>

using namespace std;

int main()
{
	int T, V, E;
	cin >> T;
	while (T--)
	{
		cin >> V >> E;
		cout << E - V + 2 << endl;
	}
}