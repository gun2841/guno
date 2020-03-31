#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
using namespace::std;


int solution(int n, int a, int b)
{
    int answer=0;
    while (a != b)
    {
        if (a % 2 == 1)
            a = a / 2 + 1;
        else
            a /= 2;

        if (b % 2 == 1)
            b = b / 2 + 1;
        else
            b /= 2;

        answer++;
    }
    return answer;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << solution(n, a, b);
}