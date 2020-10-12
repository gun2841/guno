#include <algorithm>
using namespace std;
#define ll long long
int gcd(int a, int b)
{
    int c = max(a, b),n;
     b = min(a, b);
    a = c;
    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}
long long solution(int w, int h) {
    long long answer = 1;
    int g = gcd(w, h);
    answer = ((ll)w * (ll)h) - ((ll)w + (ll)h - g);
    return answer;
}