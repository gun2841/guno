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

int solution(vector<int> nums)
{
	int answer = 0;
	int n = nums.size()/2;
    sort(nums.begin(),nums.end());
	nums.erase( unique(nums.begin(), nums.end()),nums.end());
	answer = nums.size();
	
	
	return min(n, answer);
}