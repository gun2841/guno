#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
using namespace::std;
string solution(string s) {
	string answer = "";
	string word;
	int mx = -123456789, mn = 987654321;
	stringstream ss;
	ss.str(s);
	int i = 1;
	while (ss >> word)
	{
		int n = stoi(word);
		mn = min(mn, n);
		mx = max(mx, n);
	}

	answer = answer + to_string(mn) + " " + to_string(mx);
	return answer;
}