#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<21> bb;
    bb = n;
    int cnt = bb.count();
    for (int i = 0;; i++)
    {
        n++;
        bb = n;
        if (cnt == bb.count())
            return n;
    }
    return answer;
}