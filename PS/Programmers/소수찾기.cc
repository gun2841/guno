#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace::std;

bool prime(int num)
{
	if (num == 1 || num == 0)
		return false;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int solution(string numbers) {
	set<int> st;
	for (int i = 1; i <= numbers.size(); i++)
	{
		vector<int> in;
		for (int j = 0; j < i; j++)
			in.push_back(j+1);
		for (int j = 0; j < numbers.size() - i; j++)
			in.push_back(0);
		sort(in.begin(), in.end());

		do {
			string str ="";
			str.resize(i);
			for (int j = 0; j < in.size(); j++)
				if (in[j] != 0)
					str[in[j]-1] = numbers[j];

			int d = stoi(str);
			if (prime(d)) {
				st.insert(d);
				//cout << d << endl;
			}
		} while (next_permutation(in.begin(), in.end()));
	}
	return st.size();
}