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
#include <stack>
using namespace::std;
int arr[3001] = { 0,1, };
bool prime(int d)
{
	for (int i = 2; i*i <= d; i++)
	{
		if (d % i == 0) {
			arr[d] = 1;
			return false;
		}
	}
	arr[d] = 2;
	return true;
}
int solution(vector<int> nums) {
	int n = nums.size();
	int answer = 0;
	vector<int> comb;
    arr[0]=1;arr[1] =1;arr[2]=1;
    for(int i =3;i<3000;i++)
        arr[i]=0;
	for (int i = 0; i < n - 3; i++)
		comb.push_back(0);
	comb.push_back(1);	comb.push_back(1);	comb.push_back(1);
	do {
		int d = 0;
		for (int i = 0; i < n; i++)
		{
			if (comb[i] == 1)
				d += nums[i];
		}
		if (arr[d] == 1) continue;
		else if (arr[d] == 2) answer++;
		else if (arr[d] == 0 && prime(d)){ answer++;}
	} while (next_permutation(comb.begin(), comb.end()));
	return answer;
}