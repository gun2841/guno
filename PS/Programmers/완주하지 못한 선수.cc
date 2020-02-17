#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int n = 0;
		for (int i = 0; i < completion.size(); i++)
		{
			if (participant[n] == completion[i])
			{
				n++;
			}
		}
	return participant[n];
}