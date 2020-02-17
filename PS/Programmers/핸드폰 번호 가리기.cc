#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.size();
    for(int i = 0;i<len;i++)
    {
        if(i <len -4)
        {
            phone_number[i] = '*';
        }
    }
    return phone_number;
}