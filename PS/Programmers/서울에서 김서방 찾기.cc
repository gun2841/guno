#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	int index = 0;
	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim") {
			index = i;
			string answer = "김서방은 " + to_string(index);
            	answer += "에 있다";
            	return answer;
		}
	}
	string answer = "김서방은 " + index;
	answer += "에 있다";
	return answer;
}