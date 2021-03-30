#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
#include <stack>
using namespace::std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> st;
    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement[i] == '(') st.push('(');
        else {
            st.pop();
            if (arrangement[i - 1] == '(')
                answer += st.size();
            else answer++;
        }
    }
    return answer;
}