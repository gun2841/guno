#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int pivot = 1;
    string str;
    while (n)
    {
        int d = n % 3;
        str += (d + '0');
        n /= 3;
    }
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++)
    {
        answer += ((str[i] - '0')*pivot);
        pivot *= 3;
    }

    return answer;
}