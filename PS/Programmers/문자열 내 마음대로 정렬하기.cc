#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index;
bool compare(string a, string b)
{
    if(a[index] < b[index])
        return true;
    else if (a[index] == b[index])
        return a < b ? true : false;
    else 
        return false;
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    sort(strings.begin(), strings.end(), compare);
    vector<string> answer;
    
    return strings;
}