#include <iostream>
#include <string>
#include <queue>
using namespace::std;
int main()
{
	ios_base::sync_with_stdio(false);
	queue<int> qu;

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		qu.push(i);
	cout << "<";
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++) {
			qu.push(qu.front());
			qu.pop();
		}
		cout << qu.front()<< ", ";
		qu.pop();
	}
	cout << qu.front() << ">";
}