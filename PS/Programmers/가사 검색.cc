#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <cstring>
using namespace::std;


struct Trie {
	int cnt =1;
	bool output = false;
	Trie* go[26];


	Trie() {
		memset(go, 0, sizeof(go));
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (go[i]) delete go[i];
	}
	void insert(const char* key)
	{
		if (*key == '\0')
		{
			output = true;
		}
		else
		{
			int next = *key - 'a';
			if (go[next] == NULL)
				go[next] = new Trie();
			else 
				go[next]->cnt++;
			go[next]->insert(key + 1);
		}
	}
	int find(const char* key)
	{
		int next = *key - 'a';
		if (*key == '?') {
			int tmp = 0;
			for (int k = 0; k < 26; k++)
			{
				if (go[k] != NULL)
					tmp += go[k]->cnt;
			}
			return tmp;
		}
		if (go[next] == NULL) return 0;
		if (*(key + 1) == '?') return go[next]->cnt;
		return go[next]->find(key + 1);
	}
};
Trie* top[100010];
Trie* down[100010];
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < words.size(); i++)
	{
		int s = words[i].size();
		if (top[s] == NULL) top[s] = new Trie();

		top[s]->insert(words[i].c_str());

		reverse(words[i].begin(), words[i].end());

		if (down[s] == NULL) down[s] = new Trie();

		down[s]->insert(words[i].c_str());
	}

	for (int i = 0; i < queries.size(); i++)
	{
		int s = queries[i].size();

		if (queries[i][0] == '?')
		{
			reverse(queries[i].begin(), queries[i].end());
			if (down[s] == NULL) { answer.push_back(0);  continue; }

			answer.push_back(down[s]->find(queries[i].c_str()));
		}
		else
		{
			if (top[s] == NULL) { answer.push_back(0);  continue; }

			 answer.push_back(top[s]->find(queries[i].c_str()));
		}
	}

	return answer;
}
