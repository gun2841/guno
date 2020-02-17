#include <string>
#include <vector>

using namespace std;

vector<int> solution(int a, int b) {
	vector<int> answer;
	int tmp,n,m;
	m = b;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b!=0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	answer.push_back(a);
	answer.push_back(tmp / a * m);
	return answer;
}