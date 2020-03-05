#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
using namespace::std;



long long solution(int n, vector<int> times) {
    long long answer = 100000000;
    int s = times.size();

    long long lo = 1;
    long long mid;
    long long hi = (long long)times.back() * n;
    answer = hi;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < s; i++)
            sum += mid / times[i];
        if (sum < n)
            lo = mid + 1;
        else
        {
            if (mid <= answer) {
                answer = mid;
            }

            hi = mid - 1;
        }
    }
    return answer;
}