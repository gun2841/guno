#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	string str;
	int  n, m, size_;
	cin >> n >> m;
	str = to_string(n);
	size_ = str.size();
	for (int i = 0; i < m && i < size_ *n; i++)
	{
		cout << str[i % str.size()];
	}
}