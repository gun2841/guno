#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct Trie {
	int cnt = 0;
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
		if (*key == 0)
		{
			output = true;
		}
		else
		{
			int next = *key - 'a';
			if (go[next] == NULL)
				go[next] = new Trie();

			go[next]->cnt++;
			go[next]->insert(key + 1);
		}
	}
	int find(const char* key, const int c)
	{
		const int next = *key - 'a';
		if (*key == 0 || go[next] == NULL) return c - 1;

		if (go[next]->cnt == 1) return c;
		return go[next]->find(key + 1, c + 1);
	}
};
int solution(vector<string> words) {
	int answer = 0;
	Trie* tr = new Trie();
	for (int i = 0; i < words.size(); i++)
	{
		tr->insert(words[i].c_str());
	}

	for (int i = 0; i < words.size(); i++)
	{
		answer += tr->find(words[i].c_str(), 1);
	}
	delete tr;

	return answer;
}